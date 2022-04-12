/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:14:06 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/12 15:48:12 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_unset(char *s)
{
	if (!s)
		return ;
	if (!ft_is_it_a_valid_env_name(s))
		printf("minishell_bonus: unset: `%s': not a valid identifier", s);
	if (!ft_is_it_a_valid_env_name(s))
		return ;
}
