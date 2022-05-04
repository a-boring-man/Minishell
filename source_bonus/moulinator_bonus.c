/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moulinator_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 12:20:22 by jrinna            #+#    #+#             */
/*   Updated: 2022/05/04 13:02:21 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	ft_good_parenthese_and_quote(t_minishell *mini, char *line)
{
	int	i;

	i = -1;
	mini->double_quote = 0;
	mini->single_quote = 0;
	mini->parenthese = 0;
	if (!line)
		return (0);
	while (line[++i])
	{
		if (line[i] == '(' && !mini->single_quote && !mini->double_quote)
			mini->parenthese++;
		else if (line[i] == ')' && !mini->single_quote && !mini->double_quote)
			mini->parenthese--;
		else if (line[i] == '"' && !mini->single_quote && !mini->double_quote)
			mini->double_quote++;
		else if (line[i] == '"' && !mini->single_quote && mini->double_quote)
			mini->double_quote--;
		else if (line[i] == '\'' && !mini->single_quote && !mini->double_quote)
			mini->single_quote++;
		else if (line[i] == '\'' && mini->single_quote && !mini->double_quote)
			mini->single_quote--;
		if (mini->parenthese == -1)
			break ;
	}
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
