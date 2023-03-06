/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:44:24 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/05 22:40:37 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_global global;

static void init_list_env( void )
{
	global.head_env = (t_env *)creat_new_node();

	*(global.head_env + 8) = 1;

	printf("%s %p\n",global.head_env->str, global.head_env->next );
}

static void data_init( char **env )
{
	
    ft_memset(&global, 0, sizeof(global));
    if (env)
        global.env = env;
	init_list_env();
} 
static int minishell( void )
{

	global.cmd  = readline("> ");
	add_history(global.cmd);
    if(!ft_lexer(global.cmd))
        return (0);
    if(!ft_parser())
        return(0);
	if(!ft_execute())
		return (0);
	return (0);
}

int main ( int argc, char ** argv, char ** env )
{
	printf("MINISHELL : \n");
    (void )argc;
    (void)argv;
    	data_init(env);
	while (1)
	{
		minishell();
    	freehead();
	}
}
