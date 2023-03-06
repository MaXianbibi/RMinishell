/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:44:38 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/06 14:58:32 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_lexer *ft_cd(t_lexer *tmp)
{
    int ret;
    const char * home;

    home = getenv("HOME");
    tmp = tmp->next;
    if (tmp)
        ret = chdir(tmp->identifier);
    else
        ret = chdir(home);
    if (ret)
        perror("ERROR");
    return (tmp);
}
