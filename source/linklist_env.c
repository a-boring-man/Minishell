#include "minishell_bonus.h"

t_env	*ft_lstnew_env(char *name, char *value)
{
	t_env	*new;

	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	new->name = name;
	new->value = value;
	return (new);
}

void	ft_lstadd_front_env(t_env **env, t_env *new)
{
	if (!env)
		return ;
	new->next = *env;
	*env = new;
}

void	ft_lstadd_back_env(t_env **env, t_env *new)
{
	t_env	*tmp;

	if (!env)
		return ;
	if (*env)
	{
		tmp = ft_lstlast(*env);
		tmp->next = new;
	}
	else
		*env = new;
}

t_env	*ft_lstlast(t_env *env)
{
	t_env	*tmp;

	if (!env)
		return (NULL);
	tmp = env;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstclear_env(t_env **env)
{
	t_env	*tmp;

	if (!env)
		return ;
	while (*env)
	{
		tmp = (*env)->next;
		ft_lstdelone_env(*env);
		*env = tmp;
	}
}
