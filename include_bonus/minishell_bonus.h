/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:23 by jrinna            #+#    #+#             */
/*   Updated: 2022/03/31 15:43:53 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <termios.h>
# include <unistd.h>
# include <sys/syslimits.h>
# include <dirent.h>
# include <string.h>

typedef struct s_minishell
{
	int	test;
}	t_minishell;

int		ft_strlen_s(char *s);
void	*ft_calloc(int count, int eltsize);
char	*ft_strjoin(char *s1, char *s2);
void	ft_free(char **s);
void	ft_echo(char *s, int fd, int n);

#endif