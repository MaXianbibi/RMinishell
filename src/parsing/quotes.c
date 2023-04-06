/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:48:28 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/03 16:33:56 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_parse_quotes(void)
{
	t_lexer	*tmp;
	char	*var;

	tmp = g_global.head_lexer;
	while (tmp)
	{
		if (tmp->token == VAR)
		{
			if (tmp->identifier[0] == '\"')
				var = double_quotes(tmp);
			else if (tmp->identifier[0] == '\'')
				var = ft_strldup(tmp->identifier + 1, ft_strlen(tmp->identifier)
						- 1);
			else
				var = env_var(tmp->identifier);
			free(tmp->identifier);
			tmp->identifier = var;
			tmp->token = IDENTIFIER;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}
