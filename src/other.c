/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 21:52:31 by justinmorne       #+#    #+#             */
/*   Updated: 2023/02/28 22:49:43 by justinmorne      ###   ########.fr       */
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

	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
