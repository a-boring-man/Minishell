/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:56:23 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/12 13:35:37 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*ft_expand_line(t_minishell *m, char *s)
{
	int		i;
	int		c;
	char	*new_line;

	c = 0;
	i = -1;
	new_line = ft_calloc(1, sizeof(char));
	ft_parsing_init(m);
	while (s[++i])
	{
		ft_parser_quote_and_or(m, s[i]);
		if (m->double_quote || m->single_quote || )
		{
			new_line = ft_strnjoin_f(new_line, s, c);
			s += c + 1;
		}
		else
			c++;
	}
	return (new_line);
}
