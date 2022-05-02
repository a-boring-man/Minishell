/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:20:35 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/02 10:03:08 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_is_a_built_in(char *line)
{
	if (!ft_strcmp("echo", ft_splitfirst_word(line)) || !ft_strcmp("cd",
			ft_splitfirst_word(line)) || !ft_strcmp("pwd", ft_splitfirst_word
			(line)) || !ft_strcmp("export", ft_splitfirst_word(line))
		|| !ft_strcmp("unset", ft_splitfirst_word(line)) || !ft_strcmp("env",
			ft_splitfirst_word(line)) || !ft_strcmp
		("exit", ft_splitfirst_word(line)))
		return (1);
	return (0);
}

void	ft_call_built_in(t_minishell *mini, char *line)
{
	(void)mini;
	if (!ft_strcmp("echo", ft_splitfirst_word(line)))
		ft_precall_echo(line);
	/* if (!ft_strcmp("cd", ft_splitfirst_word(line)))
		ft_precall_cd(mini, line);
	if (!ft_strcmp("pwd", ft_splitfirst_word(line)))
		ft_precall_pwd(mini, line);
	if (!ft_strcmp("export", ft_splitfirst_word(line)))
		ft_precall_export(mini, line);
	if (!ft_strcmp("unset", ft_splitfirst_word(line)))
		ft_precall_unset(mini, line);
	if (!ft_strcmp("env", ft_splitfirst_word(line)))
		ft_precall_env(mini, line);
	if (!ft_strcmp("exit", ft_splitfirst_word(line)))
		ft_precall_exit(mini, line); */
}
