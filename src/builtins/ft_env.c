/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:56:04 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/06 00:17:37 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

t_lexer * ft_env( t_lexer * tmp )
{
    t_env * tmp_env;
    tmp = tmp->next;
    
    tmp_env = global.head_env;
    while (tmp_env)
    {
        printf("%s\n", tmp_env->str);    
        tmp_env = tmp_env->next;
    }
    return (tmp);
}