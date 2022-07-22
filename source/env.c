#include "minishell_bonus.h"

void	ft_env(t_minishell *mini)
{
	t_env	*tmp;

	tmp = mini->env;
	while (tmp)
	{
		if (*ft_getenv_value(mini, tmp->name))
			ft_dprintf(1, "%s=%s\n", tmp->name, tmp->value);
		tmp = tmp->next;
	}
}

/* int	main(int ac, char **av, char **env)
{
	t_minishell	mini;

	(void)ac;
	(void)av;
	ft_env_init(&mini, env);
	ft_env(&mini);
	ft_lstclear_env(&mini.env);
} */
