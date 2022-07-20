/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_executor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 14:56:24 by jalamell          #+#    #+#             */
/*   Updated: 2022/07/20 15:17:48 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	single_built_in(t_minishell *mini, t_petit_token **pipex, int *ret)
{
	int		i;
	char	*line;

	if (pipex[1])
		return (0);
	i = 0;
	while (pipex[0][i].token_type != CMD
		&& pipex[0][i].token_type != PARENTHESE)
		++i;
	if (!ft_is_a_built_in(*(char **)(pipex[0][i].token_value)))
		return (0);
	ft_dprintf(1, "\n\n\n\nheuuu\n\n\n\n");
	line = ft_join_split((char **)(pipex[0][i].token_value));
	*ret = ft_call_built_in(mini, line);
	free(line);
	return (1);
}

static void	ft_fork(t_minishell *mini, t_petit_token *cmd, int *vars, int *fd)
{
	vars[1] = fork();
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

int	ft_ptit_executor(t_minishell *mini, t_petit_token **pipex)
{//unsafe
	int		vars[3];
	int		fd[3];

	fd[0] = 0;
	vars[0] = -1;
	if (single_built_in(mini, pipex, vars + 2))
		return (vars[2]);
	while (pipex[++(vars[0])])
	{
		fd[2] = fd[0];
		if (pipex[vars[0] + 1])
			pipe(fd);
		else
		{
			fd[1] = 1;
			fd[0] = -1;
		}
		ft_fork(mini, pipex[vars[0]], vars, fd);
	}
	vars[2] = -1;
	while (!WIFEXITED(vars[2]))
		waitpid(vars[1], vars + 2, 0);
	while (wait(0) >= 0)
		;
	return (WEXITSTATUS(vars[2]));
}
