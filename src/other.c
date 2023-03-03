/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:52:31 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/02 22:24:46 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_lexer	*creat_new_node()
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

void	freehead(t_lexer *head)
{
	t_lexer	*tmp;


	tmp = NULL;
	while (tmp != NULL)
	{
		tmp = head->next;
		if (head->identifier)
			free(head->identifier);
		free(head);
		head = tmp;
	}
}
