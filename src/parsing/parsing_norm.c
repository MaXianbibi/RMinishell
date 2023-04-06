/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_norm.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 14:26:42 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/05 20:53:22 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	norm_parsing_cmd(t_lexer *tmp)
{
	char	*str;

	if (tmp->token == IDENTIFIER)
	{
		if (find_builtins(tmp))
			return ;
		else if ((tmp->identifier[0] == '.' || tmp->identifier[0] == '/')
			&& !access(tmp->identifier, X_OK))
			tmp->token = CMD;
		else if (check_list("PATH"))
		{
			str = find(g_global.env, tmp->identifier);
			if (str)
			{
				free(tmp->identifier);
				tmp->identifier = str;
				tmp->token = CMD;
			}
		}
		tmp->token = CMD;
	}
}

void	parsing_cmd(void)
{
	t_lexer	*tmp;

	tmp = g_global.head_lexer;
	while (tmp)
	{
		norm_parsing_cmd(tmp);
		tmp = tmp->next;
		while (tmp && tmp->token != OPERATOR)
		{
			tmp->token = ARG;
			tmp = tmp->next;
		}
		if (tmp)
			tmp = tmp->next;
	}
}
