/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:02:29 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/01 17:31:58 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

int print_error(int code_error)
{
    if (code_error == GLUED_OPERATOR)
        printf("ERROR : %s \n", M_GLUED_OPERATOR);
    else if (code_error == DOUBLE_OPERATOR)
        printf("ERROR : %s \n", M_DOUBLE_OPERATOR);
    else if (code_error == OPERATOR_IN_IDENTIFIER)
        printf("ERROR : %s\n", M_OPERATOR_IN_IDENTIFIER);
	else if (code_error == NO_END)
		printf("ERROR : %s\n", M_NO_END);
		
    return (0);
}