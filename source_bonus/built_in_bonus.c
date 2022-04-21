/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_in_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:20:35 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/21 13:50:23 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_is_a_built_in(char *line)
{
	if (!strcmp("echo", ft_splitfirst_word(line)) || !strcmp("cd",
			ft_splitfirst_word(line)) || !strcmp("pwd", ft_splitfirst_word
			(line)) || !strcmp("export", ft_splitfirst_word(line))
		|| !strcmp("unset", ft_splitfirst_word(line)) || !strcmp("env",
			ft_splitfirst_word(line)) || !strcmp
		("exit", ft_splitfirst_word(line)))
		return (1);
	return (0);
}

void	ft_call_built_in(t_minishell *mini, char *line)
{
	if (!strcmp("echo", ft_splitfirst_word(line)))
		ft_precall_echo(mini, line);
	if (!strcmp("cd", ft_splitfirst_word(line)))
		ft_precall_cd(mini, line);
	if (!strcmp("pwd", ft_splitfirst_word(line)))
		ft_precall_pwd(mini, line);
	if (!strcmp("export", ft_splitfirst_word(line)))
		ft_precall_export(mini, line);
	if (!strcmp("unset", ft_splitfirst_word(line)))
		ft_precall_unset(mini, line);
	if (!strcmp("env", ft_splitfirst_word(line)))
		ft_precall_env(mini, line);
	if (!strcmp("exit", ft_splitfirst_word(line)))
		ft_precall_exit(mini, line);
}
