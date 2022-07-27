/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:11:48 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/27 12:29:17 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_count_heredoc(t_minishell *m, char *line)
{
	int	i;
	int	p;
	int	c;

	i = -1;
	p = 0;
	c = 0;
	ft_parsing_init(m);
	while (line && line[++i])
	{
		ft_parser_quote_and_or(m, line[i]);
		if (!m->single_quote && !m->double_quote && line[i] == '<' && !p)
			p = 1 - p;
		else if (!m->single_quote && !m->double_quote && line[i] == '<')
			c++;
		else
			p = 0;
	}
	m->tab_fd = ft_calloc(c + 1, sizeof(int));
	if (m->tab_fd)
		ft_memset_2(m->tab_fd, -1, c + 1);
	m->tab_lim = ft_calloc(c + 1, sizeof(char *));
}
