#include "minishell_bonus.h"

static int	ft_numeric_argument(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (!((s[i] > 8 && s[i] < 14) || s[i] == 32 || s[i] == 43 || s[i] == 45
				|| (s[i] > 47 && s[i] < 58)))
			return (1);
	}
	return (0);
}

void	ft_precall_exit(t_minishell *mini, char **split, int last_return)
{
	if (!split)
		return ;
	if (split[1] && split[2])
	{
		if (ft_numeric_argument(split[1]))
			ft_dprintf(2, "%s: exit: %s: numeric argument required\n",
				mini->name, split[1]);
		else
			ft_dprintf(2, "%s: exit: too many arguments\n", mini->name);
		return ;
	}
	last_return = ft_exit(split[1]);
	if (last_return == -1)
		ft_dprintf(2,
			"%s: exit: %s: numeric argument required\n", mini->name, split[1]);
	if (last_return == -1)
		last_return = 255;
	exit (last_return);
}
