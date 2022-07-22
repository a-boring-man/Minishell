#include "minishell_bonus.h"

int	ft_precall_export(t_minishell *mini, char **split)
{
	int		i;
	int		last_return;

	i = 1;
	last_return = 0;
	if (!split)
		return (1);
	if (ft_export(mini, split[1], 0))
		last_return = 1;
	while (split[i] && split[i + 1])
		if (ft_export(mini, split[++i], 0))
			last_return = 1;
	return (last_return);
}
