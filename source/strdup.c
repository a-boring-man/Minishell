#include "minishell_bonus.h"

char	*ft_strdup(char *s)
{
	char	*dup;
	int		i;

	dup = ft_calloc(ft_strlen_s(s) + 1, 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i])
		dup[i] = s[i];
	return (dup);
}

char	*ft_strndup(char *s, int n)
{
	char	*dup;
	int		i;

	dup = ft_calloc(ft_min(ft_strlen_s(s), n) + 1, 1);
	if (!dup)
		return (NULL);
	i = -1;
	while (s[++i] && i < n)
		dup[i] = s[i];
	return (dup);
}
