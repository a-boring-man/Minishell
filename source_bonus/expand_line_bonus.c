/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:56:23 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/13 15:59:36 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	ft_dollar(char **new_line, char **s)
{
	(void)new_line;
	(void)s;
}

static void	ft_normal_block(char **new_line, char **s, int i)
{
	*new_line = ft_strnjoin_f(*new_line, *s, i);
	*s = *s + i;
}

static void	ft_double_quote(char **new_line, char **s)
{
	int		i;

	*s += 1;
	while (**s && **s != '"')
	{
		i = 0;
		while ((*s)[i] && (*s)[i] != '"' && (*s)[i] != '$')
			i++;
		*new_line = ft_strnjoin_f(*new_line, *s, i);
		*s = *s + i;
		if (**s == '$')
			ft_dollar(new_line, s);
	}
	if (**s)
		*s += 1;
}

static void	ft_single_quote(char **new_line, char **s)
{
	int		i;

	*s += 1;
	i = 0;
	while ((*s)[i] && (*s)[i] != '\'')
		i++;
	*new_line = ft_strnjoin_f(*new_line, *s, i);
	*s = *s + i;
	if (**s)
		*s += 1;
}

char	*ft_expand_line(char *s)
{
	int		i;
	char	*new_line;

	new_line = ft_calloc(1, sizeof(char));
	while (*s)
	{
		i = 0;
		while (s[i] && s[i] != '\'' && s[i] != '"' && s[i] != '$')
			i++;
		ft_normal_block(&new_line, &s, i);
		if (*s == '"')
			ft_double_quote(&new_line, &s);
		else if (*s == '\'')
			ft_single_quote(&new_line, &s);
		else if (*s == '$')
			ft_dollar(&new_line, &s);
	}
	return (new_line);
}

int	main(void)
{
	printf("%s", ft_expand_line("je suis une sup\"erbe chaine d\"e caracter\0"));
}
