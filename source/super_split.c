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

char	**ft_super_split(t_minishell *mini, char *s, char c)
{
	char	**ret;
	int		nb_word;
	int		i[2];

	if (!s)
		return (0);
	nb_word = count_word(mini, s, c);
	*i = -1;
	ret = ft_calloc(nb_word + 1, sizeof(char *));
	if (!ret)
		return (0);
	while (++(*i) < nb_word)
	{
		while (c != '|' && *s == c)
			++s;
		i[1] = ft_count_size(mini, s, c);
		if (c != '|')
			ret[*i] = ft_expand_line(mini, ft_strndup_del(s, i[1], c));
		else
			ret[*i] = ft_strndup_del(s, i[1], c);
		s += i[1] + 1;
		if (!ret[*i])
			return (ft_free_split(ret));
	}
	return (ret);
}

char	*ft_join_split(char **split)
{
	int		i[2];
	int		tot;
	char	*ret;

	*i = -1;
	tot = 0;
	while (split[++(*i)])
	{
		i[1] = 0;
		while (split[*i][i[1]])
			++(i[1]);
		tot += i[1] + 1;
	}
	ret = ft_calloc(tot + 1, sizeof(char));
	*i = -1;
	tot = 0;
	while (split[++(*i)])
	{
		i[1] = -1;
		while (split[*i][++(i[1])])
			ret[tot + i[1]] = split[*i][i[1]];
		ret[tot + i[1]] = ' ';
		tot += i[1] + 1;
	}
	return (ret);
}
