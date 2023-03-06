/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:54:51 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/05 22:04:20 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_lexer * ft_pwd( t_lexer * tmp)
{
    char cwd[1024];
    
    tmp = tmp->next;
    if (getcwd(cwd, sizeof(cwd)))
    {
        printf("%s\n", cwd);
        return (tmp);
    } 
    perror("ERROR");
    return (tmp);
}
