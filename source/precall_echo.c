#include "minishell_bonus.h"

void	ft_precall_echo(char **split)
{
	int		n;
	int		i;

	i = 0;
	n = 0;
	if (split[1] && split[1][0] == '-')
	{
		while (split[1][++i] == 'n')
			n = 1;
		if (split[1][i] != '\0')
			n = 0;
	}
	i = 0;
	while (split[++i + n])
	{
		ft_echo(split[i + n], 1);
		if (split[i + n + 1])
			write (1, " ", 1);
	}
	if (!n)
		write(1, "\n", 1);
}
