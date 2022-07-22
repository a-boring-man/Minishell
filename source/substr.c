#include "minishell_bonus.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*substr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	substr = ft_calloc(ft_min(len, ft_strlen_s(s)) + 1, 1);
	i = -1;
	j = -1;
	if (substr)
		while (s[++i])
			if (i >= start && (i - start) < len)
				substr[++j] = s[i];
	return (substr);
}
