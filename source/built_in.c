/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:28:03 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:30:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_a_built_in_non_fork(char **split)
{
	if (split && (!ft_strcmp("cd", split[0])
			|| (!ft_strcmp("export", split[0]) && split[1])
			|| !ft_strcmp("unset", split[0])
			|| !ft_strcmp("exit", split[0])))
		return (1);
	return (0);
}

int	ft_is_a_built_in(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (split && (!ft_strcmp("echo", split[0]) || !ft_strcmp("cd", split[0])
			|| !ft_strcmp("pwd", split[0]) || !ft_strcmp("export", split[0])
			|| !ft_strcmp("unset", split[0]) || !ft_strcmp("env", split[0])
			|| !ft_strcmp("exit", split[0])))
	{
		ft_clean(split);
		return (1);
	}
	ft_clean(split);
	return (0);
}

int	ft_call_built_in(t_minishell *mini, char **split)
{
	int		last_return;

	last_return = 0;
	if (!split)
		return (1);
	if (!ft_strcmp("echo", split[0]))
		ft_precall_echo(split);
	if (!ft_strcmp("cd", split[0]))
		last_return = ft_precall_cd(mini, split);
	if (!ft_strcmp("pwd", split[0]))
		ft_pwd();
	if (!ft_strcmp("export", split[0]))
		last_return = ft_precall_export(mini, split);
	if (!ft_strcmp("unset", split[0]))
		last_return = ft_precall_unset(mini, split);
	if (!ft_strcmp("env", split[0]))
		ft_env(mini);
	if (!ft_strcmp("exit", split[0]))
		ft_precall_exit(mini, split, 0);
	return (last_return);
}
