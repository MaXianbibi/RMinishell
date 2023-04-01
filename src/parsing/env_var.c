/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_var.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:07:55 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/31 20:10:43 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*remove_single_quotes(char *str)
{
	char	*tmp;

	tmp = ft_strldup(str + 1, ft_strlen(str) - 1);
	free(str);
	return (tmp);
}

static char	*add_c(char *str, char c)
{
	char	*tmp;
	int		size;

	size = ft_strlen(str);
	tmp = ft_calloc(ft_strlen(str) + 3, 1);
	tmp[0] = c;
	ft_strlcpy(tmp + 1, str, 1024);
	tmp[size + 1] = c;
	free(str);
	return (tmp);
}

static char	*ret_var(char *identifier)
{
	t_env	*tmp_env;
	char	*str;

	tmp_env = check_list(identifier);
	if (tmp_env == &g_global.last_cmd)
		str = g_global.last_cmd.str;
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

char	*double_quotes(t_lexer *tmp)
{
	char *var;
	char **split_var;
	int i;

	i = 0;
	split_var = NULL;
	var = ft_strldup(tmp->identifier + 1, ft_strlen(tmp->identifier) - 1);
	if (ft_strchr(var, '$'))
	{
		split_var = ft_split(var, ' ');
		free(var);
		while (split_var[i])
		{
			if (ft_strchr(split_var[i], '$'))
			{
				if (split_var[i][0] == '\'')
				{
					split_var[i] = remove_single_quotes(split_var[i]);
					var = env_var(split_var[i]);
					free(split_var[i]);
					split_var[i] = add_c(var, '\'');
				}
				else
				{
					var = env_var(split_var[i]);
					free(split_var[i]);
					split_var[i] = var;
				}
			}
			i++;
		}
		var = multiple_join(split_var, 1);
		ft_free_chartable(split_var);
	}
	return (var);
}