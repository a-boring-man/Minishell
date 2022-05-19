/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_split_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jalamell <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 11:21:38 by jalamell          #+#    #+#             */
/*   Updated: 2022/05/19 12:54:45 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

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
			if (i && !(mini->double_quote + mini->single_quote
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

void	**ft_free_split(void **split)
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

	nb_word = count_word(mini, s, c);
	i = -1;
	ret = malloc((nb_word + 1) * sizeof(char *));
	if (!ret)
		return (0);
	while (++i < nb_word)
	{
		while (*s == c)
			++s;
		n = ft_count_size(mini, s, c);
		ret[i] = ft_strndup_del(s, n, c);
		s += n;
		if (!ret[i])
			return ((char **)ft_free_split((void **)ret));
	}
	return (ret);
}
