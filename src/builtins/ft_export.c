/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:55:13 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/06 15:42:48 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

static char *parsing_export(const char *str) // il faut plus de truc a verif.. je crois
{
    char *tmp;

    if (ft_strchr(str, '='))
    {
        tmp = ft_strdup(str);
        return (tmp);
    }
    tmp = calloc(ft_strlen(str) + 2, 1);
    tmp[ft_strlcpy(tmp, str, 1000)] = '=';
    return (tmp);
}

t_lexer *ft_export(t_lexer *tmp)
{
    t_env *env;

    if (!tmp->next)
        tmp = ft_env(tmp);
    else
    {
        tmp = tmp->next;
        env = (t_env *)creat_new_node();
        env->str = parsing_export(tmp->identifier);
        insert_at_head((t_lexer **)&global.head_env, (t_lexer *)env);
    }
    return (tmp);
}