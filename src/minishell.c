/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:44:24 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/05 14:24:35 by jmorneau         ###   ########.fr       */
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
	
    if(!ft_lexer("<"))
        return (0);
    if(!ft_parser())
        return(0);
	if(!ft_execute())
		return (0);
		
    // t_lexer *tmp = global.head_lexer;

    // while (tmp)
    // {
	// 	if (tmp->token != BUILTIN)
	// 	{
    //     	printf("%s %d\n", tmp->identifier, tmp->token);
	// 	}
	// 	else
	// 		tmp->ptr(tmp);
    //     tmp = tmp->next;
    // }
	
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
