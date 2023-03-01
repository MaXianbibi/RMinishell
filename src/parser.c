/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:04:44 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/01 13:38:33 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_global global;

static int double_operator( void )
{
    t_lexer * tmp;
    int i;

    i = 1;
    tmp = global.head_lexer;
    while (tmp)
    {
        if (tmp->token == OPERATOR)
            i++;
        else
            i = 0;
        if (i > 1)
            return (0);
        tmp = tmp->next;
    }
    return (1);
}

static int identifier_parsing( void )
{
    t_lexer * tmp;
    int i;

    tmp = global.head_lexer;
    while (tmp)
    {
        i = 0;
        if (tmp->token == IDENTIFIER)
        {
            while (tmp->identifier[i])
            {
                if(ft_strchr(OPERATORS, tmp->identifier[i]))
                    return (0);
                i++;
            }
        }
        tmp = tmp->next;
    }
    return (1);
}

// int parsing_cmd( void )
// {
//     t_lexer * tmp;

//     tmp = global.head_lexer;
//     while ()
//     {

//     }
        

    
// }

int ft_parser( void )
{
    if (!double_operator())
        return (print_error(DOUBLE_OPERATOR));
    if (!identifier_parsing())
        return (print_error(OPERATOR_IN_IDENTIFIER));
    return(1);
    
}
