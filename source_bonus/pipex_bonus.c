/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:05:36 by jalamell          #+#    #+#             */
/*   Updated: 2022/05/19 17:20:23 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
/*
static void	child(char *cmd, int fd[3])
{
	char	**split;

	split = split_token(cmd, fd);
	//check in/out
	//
	//execve/moulinator
}

void	ft_pipex(t_minishell *mini, char *line)
{
	if (ft_is_a_built_in(line))
		ft_call_built_in(mini, line);
	char	**lst_cmd;
	int		i;
	int		fd[3];
	int		pid;

	fd[0] = 0;
	//split |
	//lst_cmd = split(line, '|')
	//
	//foreach pipe fork
	if (!lst_cmd)
		//return error
	i = 0;
	while (lst_cmd[i])
	{
		fd[2] = fd[0];
		if (lst_cmd[i+1])
			pipe(fd);
		else
		{
			fd[1] = 1;
			fd[0] = -1;
		}
		pid = fork();
		if (!pid)
			child(lst_cmd[i], fd);
		else
		{
			close(fd[1]);
			close(fd[2]);
		}
	}
	while (wait(0) >= 0)
		;
	//return success
}
*/

t_petit_token	*ft_free_cmd(t_petit_token *cmd)
{
	int	i;

	if (!cmd)
		return (0);
	i = 0;
	while ((cmd + i)->token_type != CMD && (cmd + i)->token_type != PARENTHESE)
	{
		if ((cmd + i)->token_value)
			free((cmd + i)->token_value);
		++i;
	}
	free(cmd);
	return (0);
}

static int	ft_count_token(t_minishell *mini, char *line, int i)
{
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
dprintf(2, "%d\n", mini->char_count);
			if (i && mini->char_count <= 1)
				return (0);
			mini->char_count = 0;
			if (line[i + 1] == line[i])
				++i;
			++(mini->block);
		}
	}
	if (mini->char_count <= 1)
		return (0);
	return (mini->block + 1);
}

t_petit_token	*ft_tokenize_cmd(t_minishell *mini, char *line)
{
	const int				token_count = ft_count_token(mini, line, -1);
	t_petit_token *const	ret = ft_calloc(token_count, sizeof(t_petit_token));
	int						i;
	int						blk;

	if (!ret)
		return (0);
	(ret + token_count - 1)->token_type = CMD;
	i = 0;
	blk = 0;
	ft_parsing_init(mini);
	while (blk < token_count - 1)
	{
		while ((line[i] != '<' && line[i] != '>') || mini->single_quote
				|| mini->double_quote || mini->parenthese)
			ft_parser_quote_and_or(mini, line[i++]);
		if (line[i] == '<')
		{
			(ret + blk)->token_type = INFILE;
			if (line[i] == line[i + 1])
				(ret + blk)->token_type = HEREDOC;
		}
		if (line[i] == '>')
		{
			(ret + blk)->token_type = OUTFILE;
			if (line[i] == line[i + 1])
				(ret + blk)->token_type = APPEND;
		}
		if (line[i] == line[i + 1])
		{
			line[i] = ' ';
			++i;
		}
		line[i] = ' ';
		++i;
		while (line[i] == ' ')
			++i;
		ret[blk].token_value = ft_strndup_del(line + i, ft_count_size(mini, line + i, ' '), ' ');
		++blk;
	}
	ret[blk].token_value = ft_super_split(mini, line, ' ');
	return (ret);
}

t_petit_token	**ft_tokenize_pipe(t_minishell *mini, char *line)
{
	int				i;
	int				nb;
	int				err;
	t_petit_token	**ret;

	i = -1;
	nb = 0;
	err = 0;
	ret = malloc(2*sizeof(void *));
	if (!ret)
		return (0);
	ret[1] = 0;
	ret[0] = ft_tokenize_cmd(mini, line);
/*	while (line[++i])
	{
		ft_parser_quote_and_or(mini, line[i]);
	}
*/	return (ret);
}











