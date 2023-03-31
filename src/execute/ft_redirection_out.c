/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_out.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 14:48:51 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/28 22:28:31 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

int	check_file_out(t_lexer * tmp)
{
	int	fd;
    int permission;
    if (tmp->identifier[1])
        permission = O_WRONLY | O_CREAT | O_APPEND;
    else
        permission = O_WRONLY | O_CREAT | O_TRUNC;
        
    tmp = tmp->next;
    tmp->token = OPERATOR;    
	fd = open(tmp->identifier, permission, 0777);
    if (fd == -1)
        return (FAIL);
	return (fd);
}

int ft_redirection_out( t_lexer * tmp)
{
    if (!tmp->next)
        return (FAIL);
    global.fd_out = check_file_out(tmp);
    return (SUCCESS);   
}
