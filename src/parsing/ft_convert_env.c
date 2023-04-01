/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:08:51 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/31 20:12:24 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

static int	size_of_chained(t_env *tmp)
{
	int	i;

	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

char	**convert_env(void)
{
	char	**env;
	t_env	*tmp;
	int		size;

	tmp = g_global.head_env;
	size = size_of_chained(g_global.head_env);
	env = ft_calloc(sizeof(char *), size + 1);
	size = 0;
	while (tmp)
	{
		env[size] = ft_strdup(tmp->str);
		tmp = tmp->next;
		size++;
	}
	return (env);
}
