/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:28:13 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:30:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>

typedef struct s_cmd
{
	int		token_count;
	t_lt	*ret;
	int		i;
	int		blk;
	char	**tmp;
}	t_cmd;

static int	ft_heredoc(char *line)
{
	int		fd[2];
	char	*str;
	int		pid;

	if (pipe(fd))
		exit (0);
	pid = fork();
	if (pid < 0)
		exit (0);
	if (pid)
	{
		close(fd[1]);
		free(line);
		return (fd[0]);
	}
	str = readline("> ");
	while (str && ft_strcmp(str, line))
	{
		write(fd[1], str, ft_strlen_s(str));
		write(fd[1], "\n", 1);
		free(str);
		str = readline("> ");
	}
	ft_free((void **)&str);
	exit (0);
}

static int	ft_count_token(t_minishell *mini, char *line, int i)
{
	if (!line)
		return (0);
	ft_parsing_init(mini);
	while (*line == ' ')
		++line;
	while (line[++i])
	{
		if (i && line[i] == '(' && !(mini->single_quote
				+ mini->double_quote + mini->parenthese))
			return (0);
		ft_parser_quote_and_or(mini, line[i]);
		if ((line[i] == '<' || line[i] == '>') && !(mini->single_quote
				+ mini->double_quote + mini->parenthese))
		{
			if (i && mini->char_count < 1)
				return (0);
			mini->char_count = 0;
			if (line[i + 1] == line[i])
				++i;
			++(mini->block);
		}
	}
	if (mini->char_count < 1)
		return (0);
	return (mini->block + 1);
}

static void	redirect(t_minishell *mini, char *line, int *i,
	t_lt *token)
{
	while ((line[*i] != '<' && line[*i] != '>') || mini->single_quote
		|| mini->double_quote || mini->parenthese)
		ft_parser_quote_and_or(mini, line[(*i)++]);
	if (line[*i] == '<')
	{
		token->token_type = INFILE;
		if (line[*i] == line[*i + 1])
			token->token_type = HEREDOC;
	}
	if (line[*i] == '>')
	{
		token->token_type = OUTFILE;
		if (line[*i] == line[*i + 1])
			token->token_type = APPEND;
	}
	if (line[*i] == line[*i + 1])
		line[(*i)++] = ' ';
	line[(*i)++] = ' ';
	while (line[*i] == ' ')
		++(*i);
	token->token_value = ft_expand_line(mini, ft_strndup_del(line + *i,
				ft_count_size(mini, line + *i, ' '), ' '));
	if (token->token_type == HEREDOC)
		token->token_value = (char *) 1 + ft_heredoc(token->token_value);
}

static t_lt	*recursive(t_minishell *mini, t_cmd *vars)
{
	if (vars->tmp[0] && vars->tmp[0][0] == '(')
	{
		vars->ret[vars->blk].token_type = PARENTHESE;
		vars->i = ft_strlen_s(vars->tmp[0]);
		if (vars->tmp[0][vars->i - 1] != ')' || vars->tmp[1])
			return (ft_free_cmd(vars->ret));
		vars->tmp[0][0] = ' ';
		vars->tmp[0][vars->i - 1] = ' ';
		if (!ft_good_parenthese_and_quote(mini, vars->tmp[0]))
			return (ft_free_cmd(vars->ret));
		vars->ret[vars->blk].token_value = ft_tab_init(mini, vars->tmp[0], -1);
		if (!vars->ret[vars->blk].token_value)
			return (ft_free_cmd(vars->ret));
		ft_free_split(vars->tmp);
	}
	return (vars->ret);
}

t_lt	*ft_tokenize_cmd(t_minishell *mini, char *line)
{
	t_cmd	vars;

	vars.token_count = ft_count_token(mini, line, -1);
	vars.ret = ft_calloc(vars.token_count, sizeof(t_lt));
	if (!vars.ret)
		return (0);
	(vars.ret + vars.token_count - 1)->token_type = CMD;
	vars.i = 0;
	vars.blk = -1;
	ft_parsing_init(mini);
	while (++(vars.blk) < vars.token_count - 1)
		redirect(mini, line, &(vars.i), vars.ret + vars.blk);
	vars.tmp = ft_super_split(mini, line, ' ');
	vars.ret[vars.blk].token_value = vars.tmp;
	return (recursive(mini, &vars));
}
