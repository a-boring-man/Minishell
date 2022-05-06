/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moulinator_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:20:22 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/06 11:07:33 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

/* static void	ft_tab_init(t_minishell *mini, char *line)
{
	t_grostoken	*grostoken;

	grostoken = ft_calloc(mini->block, sizeof(t_grostoken));
	(void)line;
} */

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
	return (1);
}
	/* if (ft_is_a_built_in(line))
		ft_call_built_in(mini, line); */
