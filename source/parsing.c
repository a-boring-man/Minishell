#include "minishell_bonus.h"

void	ft_parser_quote_and_or(t_minishell *mini, char c)
{
	if (c != ' ')
		mini->char_count++;
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
	mini->char_count = 0;
}
