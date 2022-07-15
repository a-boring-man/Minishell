/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/15 11:25:18 by jrinna           ###   ########lyon.fr   */
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

void	ft_ctrl_backslash(int i)
{
	(void)i;
	rl_on_new_line();
	rl_redisplay();
}

void	ft_term_config(void)
{
	struct termios	old_config;
	struct termios	new_config;

	tcgetattr(STDIN_FILENO, &old_config);
	new_config = old_config;
	new_config.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
			| INLCR | IGNCR | ICRNL | IXON);
	new_config.c_lflag &= ~(ECHOCTL | ECHONL | ICANON | ISIG | IEXTEN);
	new_config.c_cflag &= ~(CSIZE | PARENB);
	tcsetattr(STDIN_FILENO, 0, &new_config);
}

int	main(int ac, char **av, char **env)
{
	char		*test;
	int			stop;
	t_minishell	mini;

	stop = 0;
	(void)ac;
	(void)av;
	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, ft_ctrl_backslash);
	ft_term_config();
	if (ft_env_init(&mini, env))
		exit (0); // error a fair
	while (!stop)
	{
		add_history(test);
		ft_moulinator(&mini, test);
		free(test);
		test = readline("i'm depressed exit me $> "); // gros probleme avec readline si echo -n ou ce genre de chose
	}
	ft_lstclear_env(&mini.env);
	rl_clear_history();
}
