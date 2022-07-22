#include "minishell_bonus.h"

void	ft_pwd(void)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	ft_dprintf(1, "%s\n", pwd);
	ft_free((void **) &pwd);
}
