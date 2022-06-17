/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_split_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:21:38 by jalamell          #+#    #+#             */
/*   Updated: 2022/06/17 14:43:07 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include <stdlib.h>

static int	count_word(t_minishell *mini, char *s, char c)
{
	int		ret;
	int		i;

	ret = 0;
	i = 0;
	ft_parsing_init(mini);
	while (*s)
	{
		ft_parser_quote_and_or(mini, *s);
		if (*s == c)
		{
			if ((i || c == '|') && !(mini->double_quote + mini->single_quote
					+ mini->parenthese))
			{
				++ret;
				i = 0;
			}
		}
		else
			++i;
		++s;
	}
	if (i)
		++ret;
	return (ret);
}

int	ft_count_size(t_minishell *mini, char *s, char c)
{
	int	ret;

	if (!s)
		return (0);
	ret = 0;
	ft_parsing_init(mini);
	while ((*s && *s != c && (c != ' ' || (*s != '<' && *s != '>')))
		|| mini->parenthese || mini->double_quote || mini->single_quote)
	{
		ft_parser_quote_and_or(mini, *s);
		++ret;
		++s;
	}
	return (ret);
}

char	*ft_strndup_del(char *s, int n, char c)
{
	char	*ret;

	if (!s)
		return (0);
	ret = malloc((n + 1) * sizeof(char));
	if (!ret)
		return (0);
	ret[n] = 0;
	while (n--)
	{
		ret[n] = s[n];
		s[n] = c;
	}
	return (ret);
}

char	**ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return (0);
	while (split[i])
	{
		free(split[i]);
		split[i] = 0;
		++i;
	}
	free(split);
	return (0);
}

char	**ft_super_split(t_minishell *mini, char *s, char c)
{
	char	**ret;
	int		nb_word;
	int		i;
	int		n;

	if (!s)
		return (0);
	nb_word = count_word(mini, s, c);
	i = -1;
	ret = ft_calloc(nb_word + 1, sizeof(char *));
	if (!ret)
		return (0);
	while (++i < nb_word)
	{
		while (c != '|' && *s == c)
			++s;
		n = ft_count_size(mini, s, c);
		ret[i] = ft_strndup_del(s, n, c);
		s += n + 1;
		if (!ret[i])
			return (ft_free_split(ret));
	}
	return (ret);
}

char	*ft_join_split(char **split)
{
	int		i;
	int		len;
	int		tot;
	char	*ret;

	i = -1;
	tot = 0;
	while (split[++i])
	{
		len = 0;
		while (split[i][len])
			++len;
		tot += len + 1;
	}
	ret = ft_calloc(tot + 1, sizeof(char));
	i = -1;
	tot = 0;
	while (split[++i])
	{
		len = -1;
		while (split[i][++len])
			ret[tot + len] = split[i][len];
		ret[tot + len] = ' ';
		tot += len + 1;
	}
	return (ret);
}
