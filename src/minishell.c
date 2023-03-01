/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:44:24 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/01 13:54:14 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_global global;

static void data_init( char **env )
{
    ft_memset(&global, 0, sizeof(global));

    if (env)
        global.env = env;
} 

int main ( int argc, char ** argv, char ** env )
{

    (void )argc;
    (void)argv;
    data_init(env);
    if(!ft_lexer("yo | ok < ok"))
        return (0);
    if(!ft_parser())
        return(0);
    t_lexer *tmp = global.head_lexer;

    while (tmp)
    {
        if (tmp->token == IDENTIFIER)
            printf("%s\n", tmp->identifier);
        else
            printf("%c\n", tmp->operator);
        tmp = tmp->next;
    }
    freehead(global.head_lexer);
}