/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 21:56:44 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/02 09:23:39 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"



int	ft_parse_operator(void)
{
	t_lexer	*tmp;

	tmp = g_global.head_lexer;
	while (tmp)
	{
		if (tmp->token == OPERATOR)
		{
			if (tmp->identifier)
			if (tmp->identifier[0] == '<')
			{
				if (!ft_redirection(tmp))
					return (FAIL);
			}
			if (tmp->identifier[0] == '>')
			{
				if (!ft_redirection_out(tmp))
					return (FAIL);
			}
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}
