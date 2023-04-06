/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:27:14 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/05 21:13:05 by jmorneau         ###   ########.fr       */
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

static void	print_word(t_lexer *tmp, int fd)
{
	if (tmp->identifier[0])
	{
		ft_putstr_fd(tmp->identifier, fd);
		if (tmp->next && tmp->next->token != OPERATOR)
			ft_putstr_fd(" ", fd);
	}
}

static int	fd_out(void)
{
	if (*g_global.pipe_tab)
		return (STDOUT_FILENO);
	return (g_global.fd_out);
}

t_lexer	*ft_echo(t_lexer *tmp)
{
	char	n;
	int		fd;

	fd = fd_out();
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
			print_word(tmp, fd);
			tmp = tmp->next;
		}
	}
	ft_putchar_fd(n, fd);
	return (0);
}
