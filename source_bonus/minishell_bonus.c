/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/21 10:17:15 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	g_last_error = 0;

void	ft_signal(int mode)
{
	if (mode == MAIN)
	{
		signal(SIGINT, ft_s_main);
		signal(SIGQUIT, ft_s_main);
	}
	else if (mode == EXEC)
	{
		signal(SIGINT, ft_s_exec);
		signal(SIGQUIT, ft_s_exec);
	}
	else if (mode == HERE)
	{
		signal(SIGINT, ft_s_here);
		signal(SIGQUIT, ft_s_here);
	}
}

int	main(int ac, char **av, char **env)
{
	char		*test;
	t_minishell	mini;

	(void)ac;
	(void)av;
	ft_term_config(&mini);
	ft_term_switch_nd(&mini);
	ft_signal(MAIN);
	if (ft_env_init(&mini, env))
		exit (0);
	test = readline("i'm depressed exit me $> ");
	while (test)
	{
		add_history(test);
		ft_moulinator(&mini, test);
		free(test);
		test = readline("i'm depressed exit me $> ");
	}
	ft_lstclear_env(&mini.env);
	rl_clear_history();
}
