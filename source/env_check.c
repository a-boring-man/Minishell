#include "minishell_bonus.h"

int	ft_isthere_this_env_name(t_minishell *mini, char *s)
{
	t_env	*tmp;

	tmp = mini->env;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, s))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}
