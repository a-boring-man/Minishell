/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moulinator_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:20:22 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/06 15:46:28 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	ft_tab_init(t_minishell *mini, char *line)
{
	int			i;
	char		*block_tmp;
	int			current_block;
	t_grostoken	*grostoken;

	i = -1;
	current_block = -1;
	grostoken = ft_calloc(mini->block, sizeof(t_grostoken));
	ft_parsing_init(mini);
	block_tmp = NULL;
	while (line[++i])
	{
		ft_parser_quote_and_or(mini, line[i]);
		if (!mini->et && !mini->ou)
			block_tmp = ft_strnjoin_f(block_tmp, &line[i], 1);
		else if ((mini->et && line[i + 1] == '&')
			|| (mini->ou && line[i + 1] == '|'))
		{
			grostoken[++current_block].next_operator_type = (line[i] == '|');
			if (block_tmp && block_tmp[0])
			{
				printf("block_tmp : %s\n", block_tmp);
				//grostoken[current_block].petit_token
				//	= ft_tokenize_pipe(mini, block_tmp);
				block_tmp = NULL;
			}
			else
			{
				printf("parsing error token not recognize\n");
			}
			i += 1;
			mini->et = 0;
			mini->ou = 0;
		}
		else if ((mini->et || mini->ou) && (!line[i + 1]))
			block_tmp = ft_strnjoin_f(block_tmp, &line[i], 1);
		if (mini->et == 2)
			mini->et = 0;
		if (mini->ou == 2)
			mini->ou = 0;
	}
	printf("block_tmp : %s\n", block_tmp);
	grostoken[current_block].next_operator_type = -1;
	if (block_tmp && block_tmp[0])
	{
		printf("block_tmp : %s\n", block_tmp);
		//grostoken[current_block].petit_token
		//	= ft_tokenize_pipe(mini, block_tmp);
		block_tmp = NULL;
	}
	else
	{
		printf("parsing error token not recognize\n");
	}
}

void	ft_parser_quote_and_or(t_minishell *mini, char c)
{
	if (c == '(' && !mini->single_quote && !mini->double_quote)
		mini->parenthese++;
	if (c == ')' && !mini->single_quote && !mini->double_quote)
		mini->parenthese--;
	if (c == '"' && !mini->single_quote)
		mini->double_quote = 1 - mini->double_quote;
	if (c == '\'' && !mini->double_quote)
		mini->single_quote = 1 - mini->single_quote;
	if (c == '&' && !mini->double_quote && !mini->parenthese
		&& !mini->single_quote)
		mini->et++;
	else if (mini->et)
		mini->et = 0;
	if (c == '|' && !mini->double_quote && !mini->parenthese
		&& !mini->single_quote)
		mini->ou++;
	else if (mini->ou)
		mini->ou = 0;
}

void	ft_parsing_init(t_minishell *mini)
{
	mini->double_quote = 0;
	mini->single_quote = 0;
	mini->parenthese = 0;
	mini->et = 0;
	mini->ou = 0;
	mini->block = 0;
}

int	ft_good_parenthese_and_quote(t_minishell *mini, char *line)
{
	int	i;

	i = -1;
	ft_parsing_init(mini);
	if (!line)
		return (0);
	while (line[++i])
	{
		if (!mini->block)
			mini->block++;
		ft_parser_quote_and_or(mini, line[i]);
		if (mini->parenthese == -1)
			break ;
		if (mini->et == 2 || mini->ou == 2)
			mini->block++;
		if (mini->et == 2)
			mini->et = 0;
		if (mini->ou == 2)
			mini->ou = 0;
	}
	printf("block = %d\n", mini->block);
	if (mini->double_quote || mini->parenthese || mini->single_quote)
	{
		printf("parsing error please fix your parenthese/quotes please\n");
		return (0);
	}
	return (1);
}

int	ft_moulinator(t_minishell *mini, char *line)
{
	if (!ft_good_parenthese_and_quote(mini, line))
		return (0);
	ft_tab_init(mini, line);
	return (1);
}
	/* if (ft_is_a_built_in(line))
		ft_call_built_in(mini, line); */
