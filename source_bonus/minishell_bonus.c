/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/03/25 13:12:40 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_ctrl_c(int i)
{
	(void)i;
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	main(void)
{
	char	*test;

	test = readline("i'm depressed exit me $> ");
	while (test)
	{
		test = readline("i'm depressed exit me $> ");
		if (test && *test)
			add_history(test);
		signal(SIGINT, ft_ctrl_c);
	}
	rl_clear_history();
}
