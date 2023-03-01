/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:51:50 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/01 13:57:03 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_global global;

int ft_lexer(const char * str)
{
    char ** lexer;
    int i;
    t_lexer *tmp;

    i = 0;
    if (!str)
        return (0);
    lexer = ft_split(str, ' ');
    while (lexer[i])
    {
        tmp = creat_new_node();
        insert_at_head(&global.head_lexer, tmp);
        if (ft_strchr(OPERATORS, lexer[i][0]))
        {
            if (lexer[i][1])
            {
                print_error(GLUED_OPERATOR); // ne prend pas en compte les && ou || etc..
                return (0); // free
            }
            tmp->operator = lexer[i][0];
            tmp->token = OPERATOR;

            free(lexer[i]);
        }
        else
        {
            tmp->identifier = lexer[i];
            tmp->token = IDENTIFIER;
        }
        i++;
    }
    free(lexer);
    return (1);
}