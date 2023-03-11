/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:44:38 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/11 17:20:08 by jmorneau         ###   ########.fr       */
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
    return (0);
}
