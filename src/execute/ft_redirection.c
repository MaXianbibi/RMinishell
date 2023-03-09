/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:13 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/08 22:42:22 by justinmorne      ###   ########.fr       */
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
    if (global.fd)
        close(global.fd);
    if (!tmp->next)
        return (0);
    tmp = tmp->next;
    global.fd = check_file(tmp->identifier);
    if (!global.fd)
        return (0);
    dup2(global.fd, STDIN_FILENO);
    close(global.fd);
    dup2(STDIN_FILENO, STDIN_FILENO);
    
    return (1);
}