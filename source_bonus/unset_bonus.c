/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 11:30:03 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/14 11:36:28 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_unset(t_minishell *mini, char *s)
{
	if (!s)
		return ;
	if (!ft_is_it_a_valid_env_name(s))
	{
		printf("minishell_bonus: unset: `%s': not a valid identifier", s);
		return ;
	}
	if (ft_isthere_this_env_name(mini, s))
		ft_delnode_env_ns_f(mini, s);
}

int	main(int ac, char **av, char **env)
{
	t_minishell	mini;

	(void)ac;
	(void)av;
	ft_env_init(&mini, env);
	printf("\n\n-----avant-----\n\n");
	ft_export(&mini, NULL);
	printf("\n\n-----toujours avant-----\n\n");
	ft_export(&mini, NULL);
	ft_unset(&mini, av[1]);
	printf("\n\n-----après-----\n\n");
	ft_export(&mini, NULL);
	ft_lstclear_env(&mini.env);
}
