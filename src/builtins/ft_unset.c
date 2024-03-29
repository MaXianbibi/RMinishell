/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:56:20 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/31 19:23:22 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_delete_env_node(t_env *node_to_delete)
{
	t_env	*tmp;

	tmp = g_global.head_env;
	while (tmp)
	{
		if (tmp->next == node_to_delete)
		{
			if (node_to_delete->next)
				tmp->next = node_to_delete->next;
			else
				tmp->next = NULL;
			free(node_to_delete->str);
			node_to_delete->str = NULL;
			free(node_to_delete);
			node_to_delete = NULL;
			break ;
		}
		tmp = tmp->next;
	}
}

t_lexer	*ft_unset(t_lexer *tmp)
{
	t_env	*tmp_env;

	tmp = tmp->next;
	if (!tmp)
	{
		g_global.error = ft_strdup("unset");
		print_error(NOT_ENOUGH_ARG);
	}
	else
	{
		while (tmp && tmp->token != OPERATOR)
		{
			tmp_env = check_list(tmp->identifier);
			if (tmp_env)
				ft_delete_env_node(tmp_env);
			tmp = tmp->next;
		}
	}
	return (0);
}
