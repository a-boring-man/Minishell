/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 12:39:31 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/14 13:14:40 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_env(t_minishell *mini)
{
	t_env	*tmp;

	tmp = mini->env;
	while (tmp)
	{
		if (ft_strncmp(tmp->name, "OLDPWD", ft_max(tmp->name_lengh, 6)))
			printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

/* int	main(int ac, char **av, char **env)
{
	t_minishell	mini;

	(void)ac;
	(void)av;
	ft_env_init(&mini, env);
	ft_env(&mini);
	ft_lstclear_env(&mini.env);
}
 */