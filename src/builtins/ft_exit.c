/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 21:40:45 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/10 20:22:28 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_lexer *ft_exit(t_lexer *tmp)
{
    int n;

    n = 0;
    if (tmp)
        n = ft_atoi(tmp->identifier);
    freehead();

    exit(n);
}
