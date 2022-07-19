/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/19 09:13:55 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_ctrl_c(int i)
{
	(void)i;
	rl_on_new_line();
	rl_redisplay();
	write(2, "  ", 2);
	write(2, "\b\b", 2);
	write(2, "\n", 1);
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

void	ft_ctrl_backslash(int i)
{
	(void)i;
	rl_on_new_line();
	rl_redisplay();
	write(2, "  ", 2);
	write(2, "\b\b", 2);
}

int	main(int ac, char **av, char **env)
{
	char		*test;
	t_minishell	mini;

	(void)ac;
	(void)av;
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, ft_ctrl_backslash);
	//ft_term_config(&mini);
	//ft_term_switch_nd(&mini);
	if (ft_env_init(&mini, env))
		exit (0); // error a fair
	test = readline("i'm depressed exit me $> "); // gros probleme avec readline si echo -n ou ce genre de chose
	while (test)
	{
		add_history(test);
		ft_moulinator(&mini, test);
		free(test);
		test = readline("i'm depressed exit me $> "); // gros probleme avec readline si echo -n ou ce genre de chose
	}
	ft_lstclear_env(&mini.env);
	rl_clear_history();
}
