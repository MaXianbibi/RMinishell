/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:27:14 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/28 19:06:46 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char * remove_single_quotes( char * str)
{
	char * tmp;
	
	tmp = ft_strldup(str + 1 ,ft_strlen(str) - 1);
	free(str);
	return ( tmp );
}

static int check_n(char * str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}


t_lexer *ft_echo(t_lexer *tmp)
{
	char n = '\n';

	if (tmp->next)
	{
		tmp = tmp->next;
		if (tmp->identifier[0] == '-' && !check_n(tmp->identifier + 1))
		{
			n = 0;
			tmp = tmp->next;
		}
		while (tmp && tmp->token != OPERATOR)
		{
			if (tmp->identifier[0] == '\'' || tmp->identifier[0] == '\"')
				tmp->identifier = remove_single_quotes(tmp->identifier);
			printf("%s", tmp->identifier);
			if (tmp->next && tmp->next->token != OPERATOR)
				printf(" ");
			tmp = tmp->next;
		}
	}
	else
		tmp = tmp->next;
	printf("%c", n);
	return (0);
}