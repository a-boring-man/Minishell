/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:05:36 by jalamell          #+#    #+#             */
/*   Updated: 2022/07/21 18:35:57 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include <fcntl.h>

static int	ft_heredoc(char *line)
{//unsafe
	int		fd[2];
	char	*str;
	int		pid;

	pipe(fd);
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
	if (str)
		free(str);
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

t_lt	*ft_tokenize_cmd(t_minishell *mini, char *line)
{//unsafe
	const int				token_count = ft_count_token(mini, line, -1);
	t_lt *const	ret = ft_calloc(token_count, sizeof(t_lt));
	int						i;
	int						blk;
	char					**tmp;

	if (!ret)
		return (0);
	(ret + token_count - 1)->token_type = CMD;
	i = 0;
	blk = -1;
	ft_parsing_init(mini);
	while (++blk < token_count - 1)
		redirect(mini, line, &i, ret + blk);
	tmp = ft_super_split(mini, line, ' ');
	ret[blk].token_value = tmp;
	if (tmp[0] && tmp[0][0] == '(')
	{
		ret[blk].token_type = PARENTHESE;
		i = ft_strlen_s(tmp[0]);
		if (tmp[0][i - 1] != ')' || tmp[1])
			return (ft_free_cmd(ret));
		tmp[0][0] = ' ';
		tmp[0][i - 1] = ' ';
		if (!ft_good_parenthese_and_quote(mini, tmp[0]))
			return (ft_free_cmd(ret));
		ret[blk].token_value = ft_tab_init(mini, tmp[0], -1);
		if (!ret[blk].token_value)
			return (ft_free_cmd(ret));
		ft_free_split(tmp);
	}
	return (ret);
}

t_lt	**ft_tokenize_pipe(t_minishell *mini, char *line)
{
	int				i;
	int				nb;
	t_lt			**ret;
	char **const	split = ft_super_split(mini, line, '|');

	if (!split)
		return (0);
	i = -1;
	nb = 0;
	while (split[++i])
		++nb;
	ret = ft_calloc(nb + 1, sizeof(void *));
	i = -1;
	while (ret && ++i < nb)
	{
		ret[i] = ft_tokenize_cmd(mini, split[i]);
		if (!ret[i])
			ret = ft_free_pipex(ret);
	}
	ft_free_split(split);
	return (ret);
}
