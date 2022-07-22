/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 11:28:19 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/22 11:59:31 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	if (ft_getenv_value(mini, "SHLVL") && *ft_getenv_value(mini
			, "SHLVL") && **ft_getenv_value(mini, "SHLVL"))
		**ft_getenv_value(mini, "SHLVL") += 1;
	return (0);
}
