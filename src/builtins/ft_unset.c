/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:56:20 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/06 20:22:10 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

void ft_delete_env_node( t_env * node_to_delete )
{
    t_env * tmp;

    tmp = global.head_env;
    while (tmp)
    {
        if (tmp->next == node_to_delete)
        {
            if (node_to_delete->next)
                tmp->next = node_to_delete->next;
            else
                tmp->next = NULL;
            free(node_to_delete->str);    
            node_to_delete->str = NULL;
            free(node_to_delete);
            node_to_delete = NULL;
            break ;
        }
        tmp = tmp->next;
    }
}

t_lexer *ft_unset(t_lexer *tmp)
{
    t_env * tmp_env;

    tmp = tmp->next;
    if (!tmp)
    {
        global.error = ft_strdup("unset");
        print_error(NOT_ENOUGH_ARG);
    }
    else
    {
        while (tmp && tmp->token != OPERATOR)
        {
            tmp_env = check_list(tmp->identifier);
            if (tmp_env)
                ft_delete_env_node(tmp_env);
            tmp = tmp->next;
        }
    }
    return (tmp);  
}