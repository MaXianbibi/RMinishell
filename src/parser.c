/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:04:44 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/02 22:50:39 by jmorneau         ###   ########.fr       */
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
        if (tmp->token == IDENTIFIER || tmp->token == ARG)
        {
            while (tmp->identifier[i])
            {
                if(ft_strchr(OPERATORS, tmp->identifier[i]))
				{
					global.error = tmp->identifier;
                    return (0);
				}
                i++;
            }
        }
        tmp = tmp->next;
    }
    return (1);
}

static void parsing_cmd( void )
{
    t_lexer * tmp;
	char *str;

    tmp = global.head_lexer;
    while (tmp)
    {
		if (tmp->token == IDENTIFIER)
		{
			if (!access(tmp->identifier, F_OK))
				tmp->token = CMD;
			else if (*global.env)
			{
					str = find(global.env, tmp->identifier);
					if (str)
					{
						free(tmp->identifier);
						tmp->identifier = str;
						tmp->token = CMD;
					}	
			}
		}
		tmp = tmp->next;
    }
}

int ft_parser( void )
{
    if (!double_operator())
        return (print_error(DOUBLE_OPERATOR));
    if (!identifier_parsing())
        return (print_error(OPERATOR_IN_IDENTIFIER));
	parsing_cmd(); // remplace les caractères originel par les cmd (si trouvé)
    return(1);
    
}
