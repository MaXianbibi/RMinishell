/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:55:13 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/02 15:09:05 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*parsing_export(const char *str)
{
	char	*tmp;

	if (ft_strchr(str, '='))
	{
		tmp = ft_strdup(str);
		return (tmp);
	}
	tmp = calloc(ft_strlen(str) + 2, 1);
	tmp[ft_strlcpy(tmp, str, 8192)] = '=';
	return (tmp);
}

t_env	*check_list(const char *str)
{
	t_env	*tmp;
	char	cstr[8192];
	int		i;

	if (!str || !str[0] || ft_strlen(str) >= 8192)
		return (NULL);
	if (str[0] == '?')
		return (g_global.last_cmd);
	ft_memset(cstr, 0, 8192);
	i = ft_find_index(str, '=');
	if (i)
		ft_strlcpy(cstr, str, i + 1);
	else
		ft_strlcpy(cstr, str, 8192);
	i = ft_strlen(cstr);
	tmp = g_global.head_env;
	while (tmp)
	{
		if (!ft_strncmp(cstr, tmp->str, i))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

static int	norminette(t_lexer *tmp)
{
	t_env	*env;

	tmp = tmp->next;
	while (tmp && tmp->token != OPERATOR)
	{
		env = check_list(tmp->identifier);
		if (!env)
		{
			env = (t_env *)creat_new_node();
			env->str = parsing_export(tmp->identifier);
			insert_at_head((t_lexer **)&g_global.head_env, (t_lexer *)env);
		}
		else
		{
			if (ft_find_index(tmp->identifier,
					'=') == (ft_strlen(tmp->identifier) - 1)
				|| ft_find_index(tmp->identifier, '=') == 0)
				return (0);
			free(env->str);
			env->str = strdup(tmp->identifier);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_lexer	*ft_export(t_lexer *tmp)
{
	if (!tmp->next || tmp->next->token == OPERATOR)
		tmp = ft_env(tmp);
	else
		norminette(tmp);
	return (0);
}
