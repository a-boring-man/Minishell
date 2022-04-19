/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:48:10 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/19 17:34:29 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*ft_splitname(char *s)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '=')
		i++;
	line = ft_calloc(i + 1, 1);
	if (!line)
		return (line);
	i = 0;
	while (s[i] && s[i] != '=')
	{
		line[i] = s[i];
		i++;
	}
	return (line);
}

char	*ft_splitvalue(char *s)
{
	int		i;
	int		c;
	char	*line;

	i = -1;
	c = 0;
	line = NULL;
	if (!s)
		return (NULL);
	while (s[++i])
		if (s[i] == '=')
			c++;
	if (!c)
		return (NULL);
	i = -1;
	while (*s != '=')
		s++;
	s++;
	while (s[++i])
		;
	line = ft_calloc(i + 1, 1);
	i = -1;
	while (s[++i])
		line[i] = s[i];
	return (line);
}

int	ft_env_init(t_minishell *mini, char **env)
{
	int		i;
	t_env	*new;

	i = -1;
	mini->env = NULL;
	new = NULL;
	if (!env)
		return (1);
	while (env[++i])
	{
		new = ft_lstnew_env(ft_splitname(env[i]), ft_splitvalue(env[i]));
		ft_lstadd_back_env(&(mini->env), new);
	}
	if (!ft_isthere_this_env_name(mini, "OLDPWD"))
		ft_lstadd_back_env(&(mini->env), ft_lstnew_env(
				ft_strdup("OLDPWD"), NULL));
	return (0);
}

/* int	main(int ac, char **av, char **env)
{
	t_minishell	mini;
	int			i;
	t_env		*tmp;

	i = -1;
	tmp = NULL;
	(void)ac;
	(void)av;
	if (ft_getenv(&mini, env))
		return (0);
	tmp = mini.env;
	while (tmp)
	{
		printf("%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
	ft_lstclear_env(&(mini.env));
} */
