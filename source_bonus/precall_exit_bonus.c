/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precall_exit_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 13:53:56 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/18 11:33:17 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_precall_exit(char *s)
{
	char	**split;

	split = ft_split(s, ' ');
	if (!split)
		return ;
	if (split[1] && split[2])
		printf("minishell_bonus: exit: too many arguments\n");
	last_error = ft_exit(split[1]);
	if (last_error == -1)
	{
		last_error = 255;
		printf("minishell_bonus: exit: %s: numeric argument required\n", s);
	}
	free(split);
	exit (last_error);
}
