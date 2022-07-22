#include "minishell_bonus.h"

char	*ft_strtrim(char *s1, char *set)
{
	int	start;
	int	i;
	int	end;

	start = 0;
	end = 0;
	i = 0;
	if (!s1)
		return (NULL);
	if (ft_strlen_s(s1) != 0)
		end = ft_strlen_s(s1) - 1;
	while (ft_isincharset(s1[start], set))
		start++;
	while (end && ft_isincharset(s1[end], set))
		end--;
	if (ft_strlen_s(s1) != 0 && start <= end)
		return (ft_substr(s1, start, end - start + 1));
	return (ft_calloc(1, 1));
}
