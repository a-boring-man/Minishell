#include "minishell_bonus.h"

int	ft_precall_unset(t_minishell *mini, char **split)
{
	int		i;
	int		last_return;

	i = 0;
	last_return = 0;
	if (!split)
		return (1);
	while (split[++i])
		if (ft_unset(mini, split[i]))
			last_return = 1;
	return (last_return);
}
