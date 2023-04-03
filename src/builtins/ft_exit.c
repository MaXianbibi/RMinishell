/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:40:45 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/02 16:15:03 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	free_env(void)
{
	t_env	*tmp;
	t_env	*head;

	head = g_global.head_env;
	tmp = head;
	while (tmp)
	{
		head = head->next;
		ft_free((void **)&tmp->str);
		ft_free((void **)&tmp);
		tmp = head;
	}
}

t_lexer	*ft_exit(t_lexer *tmp)
{
	int	n;

	n = 0;
	if (tmp && tmp->next)
		n = ft_atoi(tmp->next->identifier);
	freehead();
	if (g_global.last_cmd->str)
		free(g_global.last_cmd->str);
	free_env();
	free(g_global.last_cmd);
	exit(n);
}
