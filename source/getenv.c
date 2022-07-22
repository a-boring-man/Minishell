#include "minishell_bonus.h"

char	**ft_getenv_value(t_minishell *mini, char *name)
{
	t_env	*tmp;
	char	*ttmp;
	char	**tttmp;

	tmp = mini->env;
	if (!(tmp))
		return (NULL);
	if (!ft_strcmp(name, "?"))
	{
		ttmp = ft_itoa(g_last_error);
		tttmp = &ttmp;
		return (tttmp);
	}
	while (tmp)
	{
		if (!ft_strcmp(name, tmp->name))
			return (&tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
