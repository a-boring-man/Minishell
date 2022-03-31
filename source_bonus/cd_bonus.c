/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 10:31:49 by jrinna            #+#    #+#             */
/*   Updated: 2022/03/31 15:33:31 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_cd(char *s)
{
	char	*buf;
	char	*ptr;
	char	*ptr2;

	buf = ft_calloc(PATH_MAX, 1);
	getcwd(buf, PATH_MAX);
	printf("path : %s\n", buf);
	ptr = ft_strjoin(buf, "/");
	printf("test : %s\n", ptr);
	ptr2 = ft_strjoin(ptr, s);
	printf("test 2 : %s\n", ptr2);
	chdir(ptr2);
	getcwd(buf, PATH_MAX);
	printf("path after : %s", buf);
}

int	main(int ac, char **av)
{
	(void)ac;
	ft_cd(av[1]);
	return (0);
}
