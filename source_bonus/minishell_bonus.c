/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 15:49:44 by jrinna            #+#    #+#             */
/*   Updated: 2022/03/24 11:13:45 by jrinna           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	main(void)
{
	char	*test;

	while (1)
	{
		test = readline("i'm depressed exit me $> ");
		add_history(test);
		printf("%s\n", test);
		test = "haha";
		rl_replace_line(test, 0);
		rl_redisplay();
	}
}
