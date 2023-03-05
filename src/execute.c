/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:22:09 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/04 20:50:45 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

extern t_global global;

static char * ft_trim(char * str)
{
	int i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == '/')
		{
			i++;
			break ; 
		}
		i--;
	}
	if (i > 0)
		return(str + i);
	else
		return(str);
}

static int ft_execve( char * path_to_cmd, char ** arg)
{
	pid_t	id;

	id = fork();
	if (id == -1)
	{
		perror("ERROR : ");
		return (0);
	}
	if (id == 0)
	{
		if (execve(path_to_cmd, arg, global.env) == -1)
		{
			perror("ERROR : ");
			exit (1);
		}
		exit (0);
	}
	waitpid(id, NULL, 0);
	return (0);
}

static t_lexer * ft_execute_cmd( t_lexer * tmp)
{
	char *	arg[50];
	char *	path_to_cmd;
	int i;

	i = 1;
	ft_memset(arg, 0, sizeof(arg));
	path_to_cmd = tmp->identifier;
	arg[0] = ft_trim(tmp->identifier);
	tmp = tmp->next;
	while (tmp && (tmp->token == IDENTIFIER || tmp->token == ARG || tmp->token == VAR))
	{
		arg[i] = tmp->identifier;
		tmp = tmp->next;	
	}
	ft_execve(path_to_cmd, arg);	

	return (tmp);
}

int ft_execute( void )
{
	t_lexer * tmp;

	tmp = global.head_lexer;
	// if pipe . . . retourne un ptr sur t_lexer . . . je crois
	// if happen & all . . .
	while (tmp)
	{
		if (tmp->token == CMD)
			tmp = ft_execute_cmd(tmp);
		else
			tmp = tmp->next;
	}

	return (1);
}