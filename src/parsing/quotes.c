/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:48:28 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/07 18:20:26 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

int ft_parse_quotes ( void )
{
	t_lexer * tmp;
	t_env *	 tmp_env;

	tmp = global.head_lexer;
	while (tmp)
	{
		if (tmp->token == VAR)
		{
			if (tmp->identifier[0] == '$')
			{
				tmp_env = check_list(tmp->identifier + 1);
				free(tmp->identifier);
				if (tmp_env)
					tmp->identifier = ft_strdup(ft_strchr(tmp_env->str, '=') + 1);
				else
					tmp->identifier = ft_strdup("");
			}
			else if (tmp->identifier[0] == '\"')
			{
				if (ft_strchr(tmp->identifier, '$'))
				{
					
				}
			}

			tmp->token = IDENTIFIER;
		}
		tmp = tmp->next;
	}

	return (SUCCESS);
}