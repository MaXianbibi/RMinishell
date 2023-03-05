/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:27:14 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/05 17:12:51 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
	return (tmp);
}