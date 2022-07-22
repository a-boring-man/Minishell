#include "minishell_bonus.h"

int	ft_unset(t_minishell *mini, char *s)
{
	if (!s)
		return (1);
	if (!ft_is_it_a_valid_env_name(s))
	{
		ft_dprintf(2, "%s: unset: `%s': not a valid identifier", mini->name, s);
		return (1);
	}
	if (ft_isthere_this_env_name(mini, s))
		ft_delnode_env_ns_f(mini, s);
	return (0);
}

/* int	main(int ac, char **av, char **env)
{
	t_minishell	mini;

	(void)ac;
	(void)av;
	ft_env_init(&mini, env);
	printf("\n\n-----avant-----\n\n");
	ft_export(&mini, NULL);
	printf("\n\n-----toujours avant-----\n\n");
	ft_export(&mini, NULL);
	ft_unset(&mini, av[1]);
	printf("\n\n-----après-----\n\n");
	ft_export(&mini, NULL);
	ft_lstclear_env(&mini.env);
} */
