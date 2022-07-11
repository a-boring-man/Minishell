/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_env_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 11:43:06 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/11 12:03:43 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	ft_env_small_lenght(t_env *env, int j)
{
	int		i;
	t_env	*tmp;

	i = -1;
	tmp = env;
	while (tmp)
	{
		if (tmp->value)
			i++;
		if (i == j)
			return (ft_strlen_s(tmp->name)
				+ ft_strlen_s(tmp->value) + 2);
		tmp = tmp->next;
	}
	return (1);
}

static int	ft_env_big_lenght(t_env *env)
{
	int		i;
	t_env	*tmp;

	i = 0;
	tmp = env;
	while (tmp)
	{
		if (tmp->value)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static void	ft_free_tab(char **env)
{
	int	i;

	i = -1;
	while (env[++i])
		free(env[i]);
	free(env);
	return ;
}

static char	*ft_copy_tab(t_env *env, int j)
{
	int		i;
	t_env	*tmp;

	i = -1;
	tmp = env;
	while (tmp)
	{
		if (tmp->value)
			i++;
		if (i == j)
			return (ft_strjoin_f(ft_strjoin_f(tmp->name, "="), tmp->value));
		tmp = tmp->next;
	}
	return (NULL);
}

char	**ft_reverse_env(t_env *env)
{
	char	**envv;
	int		i;
	int		j;

	i = ft_env_big_lenght(env);
	j = -1;
	envv = ft_calloc(i + 1, sizeof(char *));
	if (!envv)
		return (envv);
	while (++j < i)
	{
		envv[j] = ft_calloc(ft_env_small_lenght(env, j), 1);
		if (!envv[j])
			ft_free_tab(envv);
		envv[j] = ft_copy_tab(env, j);
	}
	return (envv);
}

/* int	main(int ac, char **av, char **env)
{
	int			i;
	t_minishell	m;
	char		**renv;

	i = -1;
	(void)ac;
	(void)av;
	ft_memset(&m, 0, sizeof(t_minishell));
	ft_env_init(&m, env);
	printf("env : \n");
	while (env[++i])
		printf("%s\n", env[i]);
	printf("reversed env : \n");
	i = -1;
	renv = ft_reverse_env(m.env);
	while (renv[++i])
		printf("%s\n", renv[i]);
} */
