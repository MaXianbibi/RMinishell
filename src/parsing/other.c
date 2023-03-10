/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:52:31 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/11 17:43:42 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

t_lexer *creat_new_node()
{
	t_lexer *result;

	result = malloc(sizeof(t_lexer));
	ft_memset(result, 0, sizeof(t_lexer));
	if (result == NULL)
		return (NULL);
	result->next = NULL;
	return (result);
}

void insert_at_head(t_lexer **head, t_lexer *node_to_insert)
{
	t_lexer *tmp;

	tmp = *head;
	if (!*head)
		*head = node_to_insert;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = node_to_insert;
	}
}

void freehead()
{
	t_lexer *tmp;
	t_lexer *head;

	ft_free_chartable((char **)global.pipe_tab);
	global.pipe_tab = NULL;
	head = global.head_lexer;
	tmp = head;
	while (tmp)
	{
		head = head->next;
		if (tmp->identifier && tmp->token != BUILTIN)
		{
			free(tmp->identifier);
			tmp->identifier = NULL;
		}
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
		tmp = head;
	}
	if (global.cmd)
		free(global.cmd);
	global.cmd = NULL;
	global.head_lexer = NULL;
	
}

void lowercase_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

int size_of_chained( t_env * tmp)
{
	int i;

	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;	
	}
	return (i);
}

char ** convert_env( void )
{
	char ** env;
	t_env * tmp;
	int size;

	tmp = global.head_env;
	size = size_of_chained(global.head_env);
	env = ft_calloc(sizeof( char * ), size + 1);

	size = 0;
	while (tmp)
	{
		env[size] = ft_strdup(tmp->str);
		tmp = tmp->next;
		size++;
	}
	return (env);
}