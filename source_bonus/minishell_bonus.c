/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/27 14:43:32 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	g_last_error = 0;

static char	*cut_name(char *name)
{
	int	i;
	int	ret;

	ret = 0;
	i = -1;
	while (name[++i])
		if (name[i] == '/')
			ret = i + 1;
	return (name + ret);
}

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

static int	ft_is_only_isspace3(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'
			&& s[i] != '\f' && s[i] != '\r' && s[i] != '\v')
			return (0);
	return (1);
}

int	main(int ac, char **av, char **env)
{
	char		*test;
	t_minishell	mini;

	mini.name = cut_name(av[0]);
	(void)ac;
	ft_term_config(&mini);
	if (ft_env_init(&mini, env))
		exit (0);
	ft_term_switch_nd(&mini);
	test = readline("i'm depressed exit me $> ");
	ft_term_switch_d(&mini);
	while (test)
	{
		if (test[0])
			add_history(test);
		if (!ft_is_only_isspace3(test))
			ft_moulinator(&mini, test);
		free(test);
		ft_term_switch_nd(&mini);
		test = readline("i'm depressed exit me $> ");
		ft_term_switch_d(&mini);
	}
	ft_lstclear_env(&mini.env);
	ft_dprintf(2, "exit\n");
	rl_clear_history();
}
