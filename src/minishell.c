/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:44:24 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/01 17:46:43 by jmorneau         ###   ########.fr       */
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
    if(!ft_lexer("Echo -e \'salut a toi jeune entreprenuer !\' | wc > \"text.txt\" $VAR"))
        return (0);
    // if(!ft_parser())
    //     return(0);
    t_lexer *tmp = global.head_lexer;

    while (tmp)
    {
        printf("%s\n", tmp->identifier);
        tmp = tmp->next;
    }
    freehead(global.head_lexer);
}