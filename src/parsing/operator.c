/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:56:44 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/10 18:40:21 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;


int ft_parse_operator( void )
{
    t_lexer * tmp;

    tmp = global.head_lexer;
    while (tmp)
    {

        if (tmp->token == OPERATOR)
        {
            if (tmp->identifier[0] == '<')
            {   
                if (!ft_redirection(tmp))
                    return (FAIL);
            }
            if (tmp->identifier[0] == '>')
            {   
                if (!ft_redirection_out(tmp))
                    return (FAIL);
            }
        }
        tmp = tmp->next;
    }
    return (SUCCESS);
}