#include "minishell_bonus.h"

int	ft_precall_cd(t_minishell *mini, char **split)
{
	if (!split)
		return (1);
	return (ft_cd(mini, split[1]));
}
