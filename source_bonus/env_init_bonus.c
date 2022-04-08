/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:48:10 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/08 12:05:21 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*ft_splitname(char *env)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!env)
		return (NULL);
	while (env[i] && env[i] != '=')
		i++;
	line = ft_calloc(i + 1, 1);
	if (!line)
		return (line);
	i = 0;
	while (env[i] && env[i] != '=')
	{
		line[i] = env[i];
		i++;
	}
	return (line);
}

char	*ft_splitvalue(char *env)
{
	int		i;
	char	*line;

	i = 0;
	line = NULL;
	if (!env)
		return (NULL);
	while (*env && *env != '=')
		env++;
	env++;
	while (env[i])
		i++;
	line = ft_calloc(i + 1, 1);
	i = -1;
	while (env[++i])
		line[i] = env[i];
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
	new = ft_lstnew_env("OLDPWD", NULL);
	ft_lstadd_back_env(&(mini->env), new);
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
