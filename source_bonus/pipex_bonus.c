/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:05:36 by jalamell          #+#    #+#             */
/*   Updated: 2022/07/20 13:59:25 by jalamell         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"
#include <fcntl.h>

static int	ft_single_built_in(t_minishell *mini, t_petit_token **pipex, int *ret)
{
	int		i;
	char	*line;

	if (pipex[1])
		return (0);
	i = 0;
	while (pipex[0][i].token_type != CMD && pipex[0][i].token_type != PARENTHESE)
		++i;
	if (!ft_is_a_built_in(*(char **)(pipex[0][i].token_value)))
		return (0);
	line = ft_join_split((char **)(pipex[0][i].token_value));
	*ret = ft_call_built_in(mini, line);
	free(line);
	return (1);
}

int	ft_ptit_executor(t_minishell *mini, t_petit_token **pipex)
{//unsafe
	int		i;
	int		fd[3];
	int		pid;
	int		ret;

	fd[0] = 0;
	i = -1;
	if (ft_single_built_in(mini, pipex, &ret))
		return (ret);
	while (pipex[++i])
	{
		fd[2] = fd[0];
		if (pipex[i+1])
			pipe(fd);
		else
		{
			fd[1] = 1;
			fd[0] = -1;
		}
		pid = fork();
		if (!pid)
		{
			child(mini, pipex[i], fd);
		}
		else
		{
			if (fd[1] >= 3)
				close(fd[1]);
			if (fd[2] >= 3)
				close(fd[2]);
		}
	}
	ret = -1;
	while (!WIFEXITED(ret))
		waitpid(pid, &ret, 0);
	while (wait(0) >= 0)
		;
	return (WEXITSTATUS(ret));
}

static int	ft_heredoc(char *line)
{//unsafe
	int		fd[2];
	char	*str;

	pipe(fd);
	str = readline(">");
	while (str && ft_strcmp(str, line))
	{
		write(fd[1], str, ft_strlen_s(str));
		write(fd[1], "\n", 1);
		free(str);
		str = readline("> ");
	}
	if (str)
		free(str);
	close(fd[1]);
	return (fd[0]);
}

t_petit_token	*ft_free_cmd(t_petit_token *cmd)
{
	int	i;

	if (!cmd)
		return (0);
	i = 0;
	while ((cmd + i)->token_type != CMD && (cmd + i)->token_type != PARENTHESE)
	{
		if ((cmd + i)->token_value)
			free((cmd + i)->token_value);
		++i;
	}
	if ((cmd + i)->token_type == CMD)
		ft_free_split((cmd + i)->token_value);
	else if ((cmd + i)->token_value)
		free((cmd + i)->token_value); //TODO
	free(cmd);
	return (0);
}

static int	ft_count_token(t_minishell *mini, char *line, int i)
{
	if (!line)
		return (0);
	ft_parsing_init(mini);
	while (*line == ' ')
		++line;
	while (line[++i])
	{
		if (i && line[i] == '(' && !(mini->single_quote
				+ mini->double_quote + mini->parenthese))
			return (0);
		ft_parser_quote_and_or(mini, line[i]);
		if ((line[i] == '<' || line[i] == '>') && !(mini->single_quote
				+ mini->double_quote + mini->parenthese))
		{
			if (i && mini->char_count < 1)
				return (0);
			mini->char_count = 0;
			if (line[i + 1] == line[i])
				++i;
			++(mini->block);
		}
	}
	if (mini->char_count < 1)
		return (0);
	return (mini->block + 1);
}

t_petit_token	*ft_tokenize_cmd(t_minishell *mini, char *line)
{//unsafe
	const int				token_count = ft_count_token(mini, line, -1);
	t_petit_token *const	ret = ft_calloc(token_count, sizeof(t_petit_token));
	int						i;
	int						blk;
	char					**tmp;

	if (!ret)
		return (0);
	(ret + token_count - 1)->token_type = CMD;
	i = 0;
	blk = 0;
	ft_parsing_init(mini);
	while (blk < token_count - 1)
	{
		while ((line[i] != '<' && line[i] != '>') || mini->single_quote
			|| mini->double_quote || mini->parenthese)
			ft_parser_quote_and_or(mini, line[i++]);
		if (line[i] == '<')
		{
			(ret + blk)->token_type = INFILE;
			if (line[i] == line[i + 1])
				(ret + blk)->token_type = HEREDOC;
		}
		if (line[i] == '>')
		{
			(ret + blk)->token_type = OUTFILE;
			if (line[i] == line[i + 1])
				(ret + blk)->token_type = APPEND;
		}
		if (line[i] == line[i + 1])
		{
			line[i] = ' ';
			++i;
		}
		line[i] = ' ';
		++i;
		while (line[i] == ' ')
			++i;
		ret[blk].token_value = ft_expand_line(mini, ft_strndup_del(line + i,
				ft_count_size(mini, line + i, ' '), ' '));
		if (ret[blk].token_type == HEREDOC)
			ret[blk].token_value = (char *) 1 + ft_heredoc(ret[blk].token_value);
		++blk;
	}
	tmp = ft_super_split(mini, line, ' ');
	ret[blk].token_value = tmp;
	if (tmp[0][0] == '(')
	{
		ret[blk].token_type = PARENTHESE;
		i = ft_strlen_s(tmp[0]);
		if (tmp[0][i - 1] != ')' || tmp[1])
			return (ft_free_cmd(ret));
		tmp[0][0] = ' ';
		tmp[0][i - 1] = ' ';
		if (!ft_good_parenthese_and_quote(mini, line))
			return (ft_free_cmd(ret));
		ret[blk].token_value = ft_tab_init(mini, tmp[0], -1);
		ft_free_split(tmp);
	}
	return (ret);
}

t_petit_token	**ft_free_pipex(t_petit_token **pipex)
{
	int	i;

	if (pipex)
	{
		i = -1;
		while (pipex[++i])
			pipex[i] = ft_free_cmd(pipex[i]);
		free(pipex);
	}
	return (0);
}

t_petit_token	**ft_tokenize_pipe(t_minishell *mini, char *line)
{
	int				i;
	int				nb;
	t_petit_token	**ret;
	char **const	split = ft_super_split(mini, line, '|');

	if (!split)
		return (0);
	i = -1;
	nb = 0;
	while (split[++i])
		++nb;
	ret = ft_calloc(nb + 1, sizeof(void *));
	i = -1;
	while (ret && ++i < nb)
	{
		ret[i] = ft_tokenize_cmd(mini, split[i]);
		if (!ret[i])
			ret =  ft_free_pipex(ret);
	}
	ft_free_split(split);
	return (ret);
}
