/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:52:31 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/05 20:30:04 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_lexer	*creat_new_node(void)
{
	t_lexer	*result;

	result = malloc(sizeof(t_lexer));
	ft_memset(result, 0, sizeof(t_lexer));
	if (result == NULL)
		return (NULL);
	result->next = NULL;
	return (result);
}

void	insert_at_head(t_lexer **head, t_lexer *node_to_insert)
{
	t_lexer	*tmp;

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

void	freehead(void)
{
	t_lexer	*tmp;
	t_lexer	*head;

	ft_free_chartable((char **)g_global.pipe_tab);
	g_global.pipe_tab = NULL;
	head = g_global.head_lexer;
	tmp = head;
	while (tmp)
	{
		head = head->next;
		if (tmp->token != BUILTIN && tmp->identifier)
		{
			free(tmp->identifier);
			tmp->identifier = NULL;
		}
		ft_free((void **)&tmp);
		tmp = head;
	}
	if (g_global.cmd)
		free(g_global.cmd);
	g_global.cmd = NULL;
	g_global.head_lexer = NULL;
}

// test : a enlever
int	checkarg(void)
{
	t_env	*env;

	if (strncmp(g_global.cmd, "echo \"\'\"$USER\"\'\"", 1024))
		return (0);
	env = check_list("USER");
	if (env)
		printf("\'%s\'\n", env->str + 5);
	else
		printf("\'\'\n");
	return (1);
}

void	lowercase_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}
