/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:54:51 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/11 18:32:43 by jmorneau         ###   ########.fr       */
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
        return(0);
    } 
    perror("ERROR");
    return (tmp);
}
