/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:56:23 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/21 19:50:44 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	ft_dollar(t_minishell *m, char **new_line, char **s)
{
	char	*tmp;
	char	*ttmp;
	int		i;

	*s += 1;
	i = 0;
	if (*s[0] == '?')
		ft_dollar_if(&i, &tmp);
	else if (!*s[0] || *s[0] == ' ' || !ft_isalnum((*s)[0]))
		return (ft_dollar_elsif(&tmp, new_line));
	else
	{
		while ((*s)[i] && (ft_isalnum((*s)[i]) || (*s)[i] == '_'))
			i++;
		tmp = ft_calloc(i + 1, sizeof(char));
		i = -1;
		while ((*s)[++i] && (ft_isalnum((*s)[i]) || (*s)[i] == '_'))
			tmp[i] = (*s)[i];
	}
	ttmp = *ft_getenv_value(m, tmp);
		*new_line = ft_strjoin_f(*new_line, ttmp);
	if (!ft_strcmp("?", tmp))
		ft_free((void **)&ttmp);
	ft_free((void **)&tmp);
	*s = *s + i;
}

static void	ft_normal_block(char **new_line, char **s, int i)
{
	*new_line = ft_strnjoin_f(*new_line, *s, i);
	*s = *s + i;
}

static void	ft_double_quote(t_minishell *m, char **new_line, char **s)
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
			ft_dollar(m, new_line, s);
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

char	*ft_expand_line(t_minishell *m, char *s)
{
	int			i;
	char		*new_line;
	char *const	to_free = s;

	new_line = ft_calloc(1, sizeof(char));
	while (*s)
	{
		i = 0;
		while (s[i] && s[i] != '\'' && s[i] != '"' && s[i] != '$')
			i++;
		ft_normal_block(&new_line, &s, i);
		if (*s == '"')
			ft_double_quote(m, &new_line, &s);
		else if (*s == '\'')
			ft_single_quote(&new_line, &s);
		else if (*s == '$')
			ft_dollar(m, &new_line, &s);
	}
	free(to_free);
	return (new_line);
}
