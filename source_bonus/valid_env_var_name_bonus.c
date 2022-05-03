/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_env_var_name_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:30:20 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/03 12:25:05 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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

/* int	main(int ac, char **av)
{
	while (--ac)
		printf("%s was  : %d\n", av[ac], ft_is_it_a_valid_env_name(av[ac]));
} */
