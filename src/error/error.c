/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:02:29 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/31 19:23:48 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	print_error(int code_error)
{
	printf("%s", BRED);
	if (code_error == GLUED_OPERATOR)
		printf("ERROR : %s \n", M_GLUED_OPERATOR);
	else if (code_error == DOUBLE_OPERATOR)
		printf("ERROR : %s \n", M_DOUBLE_OPERATOR);
	else if (code_error == OPERATOR_IN_IDENTIFIER)
		printf("ERROR : %s\n", M_OPERATOR_IN_IDENTIFIER);
	else if (code_error == NO_END)
		printf("ERROR : %s\n", M_NO_END);
	else if (code_error == CMD_NOT_FOUND)
		printf("ERROR : %s\n", M_CMD_NOT_FOUND);
	else if (code_error == NOT_ENOUGH_ARG)
		printf("ERROR : %s\n", M_NOT_ENOUGH_ARG);
	if (g_global.error)
		printf("\t%s%s\n", URED, g_global.error);
	printf("%s", RESET);
	return (0);
}
