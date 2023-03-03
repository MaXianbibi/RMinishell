/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:44:24 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/02 22:52:27 by jmorneau         ###   ########.fr       */
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
static int minishell( void )
{
    if(!ft_lexer("Echo | ok < ca sa 'slait a toi' /bin/ls ping"))
        return (0);
    if(!ft_parser())
        return(0);
    t_lexer *tmp = global.head_lexer;

    while (tmp)
    {
        printf("%s\n", tmp->identifier);
        tmp = tmp->next;
    }
	return (0);
	
}

int main ( int argc, char ** argv, char ** env )
{

    (void )argc;
    (void)argv;
    data_init(env);
	minishell();
    freehead(global.head_lexer);
}
