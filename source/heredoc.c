/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:52:52 by jalamell          #+#    #+#             */
/*   Updated: 2022/07/27 12:30:35 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	do_heredoc(int fd, char *lim)
{
	char	*str;

	str = readline("> ");
	while (str && ft_strcmp(str, lim))
	{
		write(fd, str, ft_strlen_s(str));
		write(fd, "\n", 1);
		str = readline("> ");
	}
	exit (0);
}

int	ft_heredoc(t_minishell *mini)
{
	int		err;
	int		i;
	int		pid;

	i = 0;
	err = 0;
	while (err != 256 && (mini->tab_fd)[i] != -1)
	{
		pid = fork();
		if (pid < 0)
			exit (0);
		if (!pid)
			do_heredoc((mini->tab_fd)[i], (mini->tab_lim)[i]);
		close((mini->tab_fd)[i]);
		free((mini->tab_lim)[i]);
		while (wait(&err) >= 0)
			if (WIFEXITED(err) && WEXITSTATUS(err) == 1)
				g_last_error = 1;
		++i;
	}
	while ((mini->tab_fd)[i] != -1)
	{
		close((mini->tab_fd)[i]);
		free((mini->tab_lim)[i]);
		++i;
	}
	return (err);
}
