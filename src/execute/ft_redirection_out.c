/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:48:51 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/31 19:24:15 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	check_file_out(t_lexer *tmp)
{
	int	fd;
	int	permission;

	if (tmp->identifier[1])
		permission = O_WRONLY | O_CREAT | O_APPEND;
	else
		permission = O_WRONLY | O_CREAT | O_TRUNC;
	if (!tmp->next)
		return (0);
	tmp = tmp->next;
	tmp->token = OPERATOR;
	fd = open(tmp->identifier, permission, 0777);
	if (fd == -1)
		return (FAIL);
	return (fd);
}

int	ft_redirection_out(t_lexer *tmp)
{
	if (!tmp->next)
		return (FAIL);
	g_global.fd_out = check_file_out(tmp);
	return (SUCCESS);
}
