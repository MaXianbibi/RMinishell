/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:07:55 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/02 12:48:15 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ret_var(char *identifier)
{
	t_env	*tmp_env;
	char	*str;

	tmp_env = check_list(identifier);
	if (tmp_env == g_global.last_cmd)
		str = ft_strdup(g_global.last_cmd->str);
	else if (tmp_env)
		str = ft_strdup(ft_strchr(tmp_env->str, '=') + 1);
	else
		str = ft_strdup("");
	return (str);
}

char	*env_var(char *tmp)
{
	char	*str;
	char	**split_var;

	split_var = NULL;
	if (tmp[1])
	{
		if (tmp[0] == '$')
			str = ret_var(tmp + 1);
		else
		{
			split_var = ft_split(tmp, '$');
			str = ret_var(split_var[1]);
			free(split_var[1]);
			split_var[1] = str;
			str = multiple_join(split_var, 0);
			ft_free_chartable(split_var);
		}
	}
	else
		str = ft_strdup("$");
	return (str);
}
