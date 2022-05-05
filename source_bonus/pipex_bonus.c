/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:05:36 by jalamell          #+#    #+#             */
/*   Updated: 2022/05/05 15:54:59 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	**ft_pipex_split(char *line)
{
	int		cout[3];
	int		i;
	char	**ret;
}

static void	child(char *cmd, int fd[3])
{
	char	**split;

	split = split_token(cmd, fd);
	//check in/out
	//
	//execve/moulinator
}

void	ft_pipex(t_minishell *mini, char *line)
{/*
	if (ft_is_a_built_in(line))
		ft_call_built_in(mini, line);*/
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
