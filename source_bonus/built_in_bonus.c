/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:20:35 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/03 11:23:26 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_is_a_built_in(char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (!ft_strcmp("echo", split[0]) || !ft_strcmp("cd", split[0])
		|| !ft_strcmp("pwd", split[0]) || !ft_strcmp("export", split[0])
		|| !ft_strcmp("unset", split[0]) || !ft_strcmp("env", split[0])
		|| !ft_strcmp("exit", split[0]))
		return (1);
	return (0);
}

void	ft_call_built_in(t_minishell *mini, char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	(void)mini;
	if (!ft_strcmp("echo", split[0]))
		ft_precall_echo(line);
	if (!ft_strcmp("cd", split[0]))
		ft_precall_cd(mini, line);
	if (!ft_strcmp("pwd", split[0]))
		ft_pwd();
	if (!ft_strcmp("export", split[0]))
		ft_precall_export(mini, line);
	if (!ft_strcmp("unset", split[0]))
		ft_precall_unset(mini, line);
	if (!ft_strcmp("env", split[0]))
		ft_env(mini);
	/* if (!ft_strcmp("exit", split[0]))
		ft_precall_exit(mini, line); */
}
