/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:40:45 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/28 19:51:04 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

t_lexer *ft_exit(t_lexer *tmp)
{
    int n;

    n = 0;
    if (tmp)
        n = ft_atoi(tmp->identifier);
    freehead();
	free(global.last_cmd.str);
    exit(n);
}
