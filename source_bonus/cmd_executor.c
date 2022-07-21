/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_executor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:37:42 by jalamell          #+#    #+#             */
/*   Updated: 2022/07/21 14:53:52 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include <fcntl.h>

typedef struct s_child
{
	int			flags;
	int			perm;
	int			ret;
}	t_child;

static char	*ft_get_path(char **env, char *exe)
{
	char	**path;
	char	*tmp;

	if (!env || !access(exe, X_OK))
		return (exe);
	while (*env && ft_strncmp(*env, "PATH=", 5))
		++env;
	if (!*env)
		return (exe);
	path = ft_split((*env) + 5, ':');
	while (*path)
	{
		tmp = ft_strjoin_f(ft_strjoin_nf(*path, "/"), exe);
		if (!access(tmp, X_OK))
			return (tmp);
		free(tmp);
		++path;
	}
	return (exe);
}

static int	redirect(t_lt *cmd, int *fd, t_child *vars)
{
	if (cmd->token_type == INFILE)
	{
		close(fd[2]);
		fd[2] = open(cmd->token_value, O_RDONLY, 0);
	}
	if (cmd->token_type == OUTFILE)
	{
		close(fd[1]);
		fd[1] = open(cmd->token_value, vars->flags | O_TRUNC, vars->perm);
	}
	if (cmd->token_type == HEREDOC)
	{
		close(fd[2]);
		fd[2] = (int) cmd->token_value - 1;
	}
	if (cmd->token_type == APPEND)
	{
		close(fd[1]);
		fd[1] = open(cmd->token_value, vars->flags | O_APPEND, vars->perm);
	}
	if (fd[2] < 0)
		return (ft_dprintf(2, "minishell: %s: No such file or directory\n",
				cmd->token_value));
	return (0);
}

static void	execute_cmd(t_minishell *mini, t_lt *cmd, t_child *vars)
{
	char	**line;

	if (ft_is_a_built_in(*(char **)(cmd->token_value)))
		vars->ret = ft_call_built_in(mini, (char **)(cmd->token_value));
	else if (*(char **)(cmd->token_value))
	{
		line = ft_reverse_env(mini->env);
		execve(ft_get_path(line, *(char **)(cmd->token_value)),
			cmd->token_value, line);
		ft_dprintf(2, "minishell: %s: command not found\n",
			*(char **)(cmd->token_value));
		free(line);
		exit(127);
	}
}

void	child(t_minishell *mini, t_lt *cmd, int fd[3])
{//unsafe
	t_child	vars;

	vars.flags = O_WRONLY | O_CREAT;
	vars.perm = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	ft_term_switch_d(mini);
	if (fd[0] >= 0)
		close(fd[0]);
	while (cmd->token_type != CMD && cmd->token_type != PARENTHESE)
		if (redirect(cmd++, fd, &vars))
			exit (1);
	if (fd[1] != 1)
		dup2(fd[1], STDOUT_FILENO);
	if (fd[2] != 0)
		dup2(fd[2], STDIN_FILENO);
	if (cmd->token_type == CMD)
		execute_cmd(mini, cmd, &vars);
	else
	{
		vars.ret = ft_executor(mini, cmd->token_value);
	}
	exit(vars.ret);
}
