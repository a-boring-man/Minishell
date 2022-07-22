/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_stuff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:29:52 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:30:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_term_switch_nd(t_minishell *m)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &m->no_display);
}

void	ft_term_switch_d(t_minishell *m)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &m->display);
}

void	ft_term_config(t_minishell *m)
{
	tcgetattr(STDIN_FILENO, &m->display);
	m->no_display = m->display;
	m->no_display.c_cc[VQUIT] = 0;
	m->no_display.c_lflag &= ~(ECHOCTL);
}
