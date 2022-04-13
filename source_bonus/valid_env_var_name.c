/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_env_var_name.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 14:45:15 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/13 12:27:41 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_is_it_a_valid_env_name(char *name)
{
	int	i;

	i = -1;
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
