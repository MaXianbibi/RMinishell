/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:56:04 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/31 19:06:01 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_lexer	*ft_env(t_lexer *tmp)
{
	t_env	*tmp_env;

	tmp = tmp->next;
	tmp_env = g_global.head_env;
	while (tmp_env)
	{
		printf("%s\n", tmp_env->str);
		tmp_env = tmp_env->next;
	}
	return (0);
}
