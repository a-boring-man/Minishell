/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_executor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:56:24 by jalamell          #+#    #+#             */
/*   Updated: 2022/07/21 17:09:37 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include "errno.h"

static int	single_built_in(t_minishell *mini, t_lt **pipex, int *ret)
{
	int		i;

	if (pipex[1])
		return (0);
	i = 0;
	while (pipex[0][i].token_type != CMD
		&& pipex[0][i].token_type != PARENTHESE)
		++i;
	if (pipex[0][i].token_type == PARENTHESE)
		return (0);
	if (!ft_is_a_built_in_non_fork((char **)(pipex[0][i].token_value)))
		return (0);
	*ret = ft_call_built_in(mini, (char **)(pipex[0][i].token_value));
	return (1);
}

static void	ft_fork(t_minishell *mini, t_lt *cmd, int *vars, int *fd)
{
	vars[1] = fork();
	if (vars[1] < 0)
		exit (0);
	if (!(vars[1]))
		child(mini, cmd, fd);
	else
	{
		if (fd[1] >= 3)
			close(fd[1]);
		if (fd[2] >= 3)
			close(fd[2]);
	}
}

static void	super_wait(int *vars)
{
	vars[2] = wait(vars + 3);
	while (vars[2] >= 0)
	{
		if (WIFSIGNALED(vars[3]) && WTERMSIG(vars[3]) == 2)
		{
			ft_putstr_fd("\n", 2);
			vars[4] = 130;
		}
		else if (WIFSIGNALED(vars[3]) && WTERMSIG(vars[3]) == 3)
		{
			ft_putstr_fd("Quit : 3\n", 2);
			vars[4] = 131;
		}
		else if (vars[2] == vars[1] && WIFEXITED(vars[3]))
			vars[4] = WEXITSTATUS(vars[3]);
		vars[2] = wait(vars + 3);
	}
}

int	ft_ptit_executor(t_minishell *mini, t_lt **pipex)
{
	int		vars[5];
	int		fd[3];

	fd[0] = 0;
	vars[0] = -1;
	if (single_built_in(mini, pipex, vars + 2))
		return (vars[2]);
	while (pipex[++(vars[0])])
	{
		fd[2] = fd[0];
		if (pipex[vars[0] + 1])
		{
			if (pipe(fd))
				exit (errno);
		}
		else
		{
			fd[1] = 1;
			fd[0] = -1;
		}
		ft_fork(mini, pipex[vars[0]], vars, fd);
	}
	super_wait(vars);
	return (vars[4]);
}
