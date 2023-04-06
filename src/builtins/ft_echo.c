/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:27:14 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/05 19:19:55 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_n(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'n')
			return (1);
		i++;
	}
	return (0);
}

t_lexer	*ft_echo(t_lexer *tmp)
{
	char	n;

	n = '\n';
	if (checkarg())
		return (0);
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
			if (tmp->identifier[0])
			{
				ft_putstr_fd(tmp->identifier, g_global.fd_out);
				if (tmp->next && tmp->next->token != OPERATOR)
					ft_putstr_fd(" ", g_global.fd_out);
			}
			tmp = tmp->next;
		}
	}
	ft_putchar_fd(n, g_global.fd_out);
	return (0);
}
