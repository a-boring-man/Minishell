/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_line_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 11:56:23 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/19 12:46:47 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	ft_dollar(t_minishell *m, char **new_line, char **s)
{
	char	*tmp;
	int		i;

	*s += 1;
	i = 0;
	if (*s[0] == '?')
	{
		i = 1;
		tmp = ft_calloc(i + 1, sizeof(char));
		tmp[0] = '?';
	}
	else if (!*s[0] || *s[0] == ' ' || !ft_isalnum((*s)[0]))
	{
		tmp = ft_calloc(2, sizeof(char));
		tmp[0]= '$';
		*new_line = ft_strjoin_f(*new_line, tmp);
		ft_free((void **)&tmp);
		return ;
	}
	else
	{
		while ((*s)[i] && (ft_isalnum((*s)[i]) || (*s)[i] == '_'))
			i++;
		tmp = ft_calloc(i + 1, sizeof(char));
		i = -1;
		while ((*s)[++i] && (ft_isalnum((*s)[i]) || (*s)[i] == '_'))
			tmp[i] = (*s)[i];
	}
	if (ft_getenv_value(m, tmp))
		*new_line = ft_strjoin_f(*new_line, *ft_getenv_value(m, tmp));
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

/* int	main(int ac, char **av, char **env)
{
	t_minishell	m;

	(void)ac;
	(void)av;
	ft_term_config();
	if (ft_env_init(&m, env))
		exit (0);
	printf("%s", ft_expand_line(&m, "je suis une sup\"e'rbe\" $PATH chaine' de car'acter\0"));
} */
