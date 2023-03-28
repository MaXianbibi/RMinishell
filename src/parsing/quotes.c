/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:48:28 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/28 18:48:42 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

int ft_parse_quotes(void)
{
	t_lexer *tmp;
	char *var;

	tmp = global.head_lexer;
	while (tmp)
	{
		if (tmp->token == VAR)
		{
			if (tmp->identifier[0] == '\"')
				var = double_quotes(tmp);
			else if (tmp->identifier[0] == '\'')
				var = ft_strldup(tmp->identifier + 1, ft_strlen(tmp->identifier) - 1);
			else
				var = env_var(tmp->identifier);
			free(tmp->identifier);
			tmp->identifier = var;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}