#include "minishell_bonus.h"

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
