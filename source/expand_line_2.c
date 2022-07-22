#include "minishell_bonus.h"

void	ft_dollar_if(int *i, char **tmp)
{
	*i = 1;
	*tmp = ft_calloc(2, sizeof(char));
	(*tmp)[0] = '?';
}

void	ft_dollar_elsif(char **tmp, char **new_line)
{
	*tmp = ft_calloc(2, sizeof(char));
	(*tmp)[0] = '$';
	*new_line = ft_strjoin_f(*new_line, *tmp);
	ft_free((void **)tmp);
	return ;
}
