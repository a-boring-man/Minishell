/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:29:26 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:30:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_s_main(int s)
{
	if (s == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	if (s == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}

void	ft_s_exec(int s)
{
	if (s == SIGINT)
		return ;
	if (s == SIGQUIT)
		return ;
}

void	ft_s_here(int s)
{
	if (s == SIGINT)
	{
		ft_putstr_fd("\n", 2);
		rl_on_new_line();
		rl_replace_line("", 0);
		exit(1);
	}
	if (s == SIGQUIT)
	{
		rl_on_new_line();
		rl_redisplay();
	}
}
