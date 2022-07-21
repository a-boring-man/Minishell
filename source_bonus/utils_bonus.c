/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 09:28:03 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/21 17:01:30 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = -1;
	if (s && fd > -1)
	{
		while (s[++i])
			write(fd, &s[i], 1);
	}
}

void	ft_putchar_fd(char c, int fd)
{
	if (fd > -1)
		write(fd, &c, 1);
}

void	ft_clean(char **tab)
{
	int	j;

	j = -1;
	if (!tab)
		return ;
	while (tab[++j])
		free(tab[j]);
	free(tab);
	return ;
}

void	ft_mini_et_ou_reset(t_minishell *m)
{
	m->et = 0;
	m->ou = 0;
}

void	ft_bt_ss(t_minishell *mini, char c, t_bt *gt, char **block_tmp)
{
	char	*tmp;

ft_dprintf(2, "dans segmentor suit : block tmp -%s-\n", *block_tmp);
	gt[mini->cb].next_operator_type = (c == '|');
ft_dprintf(2, "dans segmentor suite : nextopp -%d-\n", gt[mini->cb].next_operator_type);
	tmp = ft_strndup(*block_tmp, ft_strlen_s(*block_tmp) - 1);
ft_dprintf(2, "dans segmentor suite : tmp -%s-\n", tmp);
	gt[mini->cb++].lt = ft_tokenize_pipe(mini, tmp);
ft_dprintf(2, "dans segmentor suite : after tokenizepipe-%p-\n", gt[mini->cb - 1].lt);
	ft_free((void **)&tmp);
}
