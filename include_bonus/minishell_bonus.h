/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:23 by jrinna            #+#    #+#             */
/*   Updated: 2022/07/27 12:05:48 by jalamell         ###   ########lyon.fr   */
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
# include <stdarg.h>

# define ET 0
# define OU 1
# define MAIN 2
# define EXEC 3
# define HERE 4

extern int	g_last_error;

typedef enum e_token_type
{
	INFILE,
	OUTFILE,
	HEREDOC,
	APPEND,
	CMD,
	PARENTHESE
}	t_token_type;

typedef struct s_lt
{
	t_token_type	token_type;
	void			*token_value;
}	t_lt;

typedef struct s_bt
{
	int		next_operator_type;
	t_lt	**lt;
}	t_bt;

typedef struct s_env
{
	int				index;
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

typedef struct s_echo
{
	int	n;
	int	i;
	int	j;
	int	cs;
	int	supern;
}	t_echo;

typedef struct s_minishell
{
	char			*name;
	int				*tab_fd;
	char			**tab_lim;
	int				double_quote;
	int				single_quote;
	int				parenthese;
	int				et;
	int				ou;
	int				char_count;
	int				block;
	int				cb;
	t_env			*env;
	struct termios	display;
	struct termios	no_display;
}	t_minishell;

int		ft_heredoc(t_minishell *mini);
t_lt	*ft_tokenize_cmd(t_minishell *mini, char *line);
t_lt	*ft_free_cmd(t_lt *cmd);
void	child(t_minishell *mini, t_lt *cmd, int fd[3]);
t_lt	**ft_tokenize_pipe(t_minishell *mini, char *line);
t_bt	*ft_tab_init(t_minishell *mini, char *line, int i);
char	**ft_super_split(t_minishell *mini, char *s, char c);
char	**ft_free_split(char **split);
char	*ft_join_split(char **split);
char	*ft_strndup_del(char *s, int n, char c);
int		ft_count_size(t_minishell *mini, char *s, char c);
void	ft_memset(void *block, int c, unsigned long size);
int		ft_strlen_s(char *s);
void	*ft_calloc(int count, int eltsize);
char	*ft_strjoin_f(char *s1, char *s2);
char	*ft_strjoin_nf(char *s1, char *s2);
void	ft_free(void **s);
void	ft_echo(char *s, int fd);
void	ft_lstdelone_env(t_env *env);
t_env	*ft_lstnew_env(char *name, char *value);
void	ft_lstadd_front_env(t_env **env, t_env *new);
void	ft_lstadd_back_env(t_env **env, t_env *new);
t_env	*ft_lstlast(t_env *env);
void	ft_lstclear_env(t_env **env);
int		ft_strcmp(char *s1, char *s2);
int		ft_isthere_this_env_name(t_minishell *mini, char *s);
char	**ft_getenv_value(t_minishell *mini, char *name);
int		ft_env_init(t_minishell *mini, char **env);
int		ft_strncmp(char *s1, char *s2, int size);
char	*ft_splitname(char *s);
char	*ft_splitvalue(char *s);
int		ft_isalnum(int c);
int		ft_isdigit(int c);
int		ft_isalpha(int c);
int		ft_is_it_a_valid_env_name(char *name);
int		ft_unset(t_minishell *mini, char *s);
void	ft_delnode_env_ns_f(t_minishell *mini, char *name);
int		ft_export(t_minishell *mini, char *s, int f);
char	*ft_strdup(char *s);
char	*ft_splitfirst_word(char *line);
int		ft_moulinator(t_minishell *mini, char *line);
int		ft_is_a_built_in(char *line);
char	**ft_split(char *s, char c);
int		ft_call_built_in(t_minishell *mini, char **split);
void	ft_precall_echo(char **split);
int		ft_precall_cd(t_minishell *mini, char **split);
int		ft_cd(t_minishell *mini, char *s);
int		ft_precall_export(t_minishell *mini, char **split);
void	ft_pwd(void);
void	ft_env(t_minishell *mini);
int		ft_precall_unset(t_minishell *mini, char **split);
int		ft_good_parenthese_and_quote(t_minishell *mini, char *line);
void	ft_parser_quote_and_or(t_minishell *mini, char c);
void	ft_parsing_init(t_minishell *mini);
char	*ft_strnjoin_f(char *s1, char *s2, unsigned int n);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
char	*ft_strndup(char *s, int n);
char	*ft_strtrim(char *s1, char *set);
int		ft_isincharset(char c, char *charset);
char	*ft_substr(char *s, int start, int len);
int		ft_executor(t_minishell *mini, t_bt *gt);
int		ft_ptit_executor(t_minishell *mini, t_lt **pipex);
t_lt	**ft_free_pipex(t_lt **pipex);
char	**ft_reverse_env(t_env *env);
void	ft_term_config(t_minishell *m);
void	ft_term_switch_d(t_minishell *m);
void	ft_term_switch_nd(t_minishell *m);
char	*ft_itoa(int n);
int		ft_super_atol(char *s);
void	ft_precall_exit(t_minishell *mini, char **split, int last_return);
int		ft_exit(char *s);
char	*ft_expand_line(t_minishell *m, char *s);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_dprintf(int fd, const char *format, ...);
void	ft_dollar_if(int *i, char **tmp);
void	ft_dollar_elsif(char **tmp, char **new_line);
void	ft_clean(char **tab);
int		ft_free_big_token(t_bt **gt, int cb, int mode);
void	ft_signal(int mode);
void	ft_s_here(int s);
void	ft_s_exec(int s);
void	ft_s_main(int s);
int		ft_is_a_built_in_non_fork(char **split);
void	ft_mini_et_ou_reset(t_minishell *m);
void	ft_bt_ss(t_minishell *mini, char c, t_bt *gt, char **block_tmp);
void	ft_ranking_reset(t_env **env);
void	ft_dollar_end_if(t_minishell *m, char **ttmp, char *tmp);
void	ft_count_heredoc(t_minishell *m, char *line);

#endif
