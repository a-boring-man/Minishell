/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/03/29 11:03:38 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_ctrl_c(int i)
{
	(void)i;
	printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

int	main(void)
{
	char			*test;
	struct termios	config;
	struct termios	sconfig;

	test = malloc(5);
	test = "oups";
	signal(SIGINT, ft_ctrl_c);
	printf("test : %d", tcgetattr(0, &config));
	sconfig = config;
	tcsetattr(0, 0, &sconfig);
	sconfig.c_lflag &= ~ECHOCTL;
	while (test)
	{
		test = readline("i'm depressed exit me $> ");
		if (test && *test)
			add_history(test);
		free(test);
	}
	rl_clear_history();
}
