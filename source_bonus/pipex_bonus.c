/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:05:36 by jalamell          #+#    #+#             */
/*   Updated: 2022/05/06 15:50:05 by jalamell         ###   ########lyon.fr   */
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


int	ft_count_token(t_minishell *mini, char *line)
{
	int		i;
	int		ret;
	int		cmd;

	cmd = 0;
	ret = 0;
	i = 0;
	while (line[i])
	{
		while (line[i] == ' ')
			++i;
		if (line[i] == '<' || line[i] == '>')
		{
			if (line[i + 1] == line[i])
				++i;
			++i;
			++ret;
		}
	}
}

t_petit_token	*ft_tokenize_cmd(t_minishell *mini, char *line)
{
	t_petit_token	*ret;
	int				i;
	int				token_count;
	int				token_valid;
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











