/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:23 by jrinna            #+#    #+#             */
/*   Updated: 2022/04/19 13:04:50 by jrinna           ###   ########lyon.fr   */
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

typedef struct s_env
{
	int				index;
	int				name_lengh;
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_minishell
{
	int		test;
	t_env	*env;
}	t_minishell;

int		ft_strlen_s(char *s);
void	*ft_calloc(int count, int eltsize);
char	*ft_strjoin_f(char *s1, char *s2);
char	*ft_strjoin_nf(char *s1, char *s2);
void	ft_free(void **s);
void	ft_echo(char *s, int fd, int n);
void	ft_lstdelone_env(t_env *env);
t_env	*ft_lstnew_env(char *name, char *value);
void	ft_lstadd_front_env(t_env **env, t_env *new);
void	ft_lstadd_back_env(t_env **env, t_env *new);
t_env	*ft_lstlast(t_env *env);
void	ft_lstclear_env(t_env **env);
int		ft_strcmp(char *s1, char *s2);
/**
 * @brief return 1 if the variable specified by name exist in the environement 0 if not
 * 
 * @param mini 
 * @param s 
 * @return int 
 */
int		ft_isthere_this_env_name(t_minishell *mini, char *s);
/**
 * @brief renvoie l'adress de la chaine de caracter value de la variable d'environement name ou null si env est vide, l'adress peut contenir un pointer null si la valeur n'as pas été initialisé
 * 
 * @param mini 
 * @param name 
 * @return char** 
 */
char	**ft_getenv_value(t_minishell *mini, char *name);
int		ft_env_init(t_minishell *mini, char **env);
int		ft_strncmp(char *s1, char *s2, int size);
char	*ft_splitname(char *s);
char	*ft_splitvalue(char *s);
int		ft_max(int a, int b);
int		ft_contain_a_charset_ns(char *s, char *charset);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
/**
 * @brief return 1 if the name is a correct name for a environemental variable or 0 if it's not
 * 
 * @param name 
 * @return int 
 */
int		ft_is_it_a_valid_env_name(char *name);
void	ft_unset(t_minishell *mini, char *s);
void	ft_delnode_env_ns_f(t_minishell *mini, char *name);
int		ft_export(t_minishell *mini, char *s);
char	*ft_strdup(char *s);

#endif