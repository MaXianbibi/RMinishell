/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:27:14 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/10 20:17:05 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_lexer *ft_echo(t_lexer *tmp)
{
	char n = '\n';

	if (tmp->next)
	{
		tmp = tmp->next;
		if (!ft_strncmp(tmp->identifier, "-n", 100))
		{
			n = 0;
			tmp = tmp->next;
		}
		while (tmp && tmp->token != OPERATOR)
		{
			printf("%s", tmp->identifier);
			if (tmp->next && tmp->next->token != OPERATOR)
				printf(" ");
			tmp = tmp->next;
		}
	}
	else
		tmp = tmp->next;
	printf("%c", n);
	exit (0);
}