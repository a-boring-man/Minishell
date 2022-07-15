/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   termios_stuff_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 11:49:11 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/15 14:14:23 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_term_switch_nd(t_minishell *m)
{
	tcsetattr(STDIN_FILENO, 0, &m->no_display);
}

void	ft_term_switch_d(t_minishell *m)
{
	tcsetattr(STDIN_FILENO, 0, &m->display);
}

void	ft_term_config(t_minishell *m)
{
	tcgetattr(STDIN_FILENO, &m->display);
	m->no_display = m->display;
	m->no_display.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP
			| INLCR | IGNCR | ICRNL | IXON);
	m->no_display.c_lflag &= ~(ECHOCTL | ECHONL | ICANON | ISIG | IEXTEN);
	m->no_display.c_cflag &= ~(CSIZE | PARENB);
}
