/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:53:27 by jalamell          #+#    #+#             */
/*   Updated: 2022/07/27 13:02:43 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	do_heredoc(int fd, char *lim)
{
	char	*str;
	int		pid;

	ft_signal(HERE);
	pid = fork();
	if (pid < 0)
		exit (0);
	if (pid)
	{
		ft_signal(EXEC);
		return ;
	}
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

	i = 0;
	err = 0;
	while (err != 256 && (mini->tab_fd)[i] != -1)
	{
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
	free(mini->tab_fd);
	free(mini->tab_lim);
	return (err);
}
