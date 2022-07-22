/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_env_var_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:30:03 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:36:42 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_it_a_valid_env_name(char *name)
{
	int	i;

	i = -1;
	if (!name[0])
		return (0);
	while (name[++i])
		if ((i == 0 && !ft_isalpha(name[i]) && name[i] != '_')
			|| (i != 0 && !ft_isalnum(name[i]) && name[i] != '_'))
			return (0);
	return (1);
}
