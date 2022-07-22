#include "minishell_bonus.h"

int	ft_isalpha(int c)
{
	return ((c > 64 && c < 91) || (c > 96 && c < 123));
}

int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
