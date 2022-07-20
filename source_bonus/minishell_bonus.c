/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/20 12:22:49 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	g_last_error = 0;

void	ft_ctrl_c(int i)
{
	(void)i;
	ft_dprintf(1, "\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_ctrl_backslash(int i)
{
	(void)i;
	rl_on_new_line();
	rl_redisplay();
	ft_dprintf(2, "Quit: 3");
}

int	main(int ac, char **av, char **env)
{
	char		*test;
	t_minishell	mini;

	(void)ac;
	(void)av;
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, ft_ctrl_backslash);
	ft_term_config(&mini);
	ft_term_switch_nd(&mini);
	if (ft_env_init(&mini, env))
		exit (0); // error a fair
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
