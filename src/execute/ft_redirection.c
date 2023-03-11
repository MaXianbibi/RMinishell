/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:13 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/10 18:33:40 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

static int	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		perror("Error ");
		close(fd);
		return (0);
	}
	return (fd);
}


int ft_redirection( t_lexer * tmp)
{
    if (!tmp->next)
        return (0);
    tmp = tmp->next;
    tmp->token = OPERATOR;
    global.fd[0] = check_file(tmp->identifier);
    if (!global.fd[0])
        return (0);
    if(dup2(global.fd[0], STDIN_FILENO) == -1)
        return (0);
    close(global.fd[0]);
    return (1);
}