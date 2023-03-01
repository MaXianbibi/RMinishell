/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:02:29 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/01 13:05:30 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int print_error(int code_error)
{
    if (code_error == GLUED_OPERATOR)
        printf("ERROR : %s \n", M_GLUED_OPERATOR);
    if (code_error == DOUBLE_OPERATOR)
        printf("ERROR : %s \n", M_DOUBLE_OPERATOR);
    if (code_error == OPERATOR_IN_IDENTIFIER)
        printf("ERROR : %s\n", M_OPERATOR_IN_IDENTIFIER);
    return (0);
}