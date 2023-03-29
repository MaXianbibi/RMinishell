/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:47:16 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/28 19:32:52 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_MINISHELL_H
# define D_MINISHELL_H

#include <stdio.h>

# define SUCCESS 1
# define FAIL 0

#define OPERATORS "|&;<>()`\\*[#˜%"

#define VAR_OPERATORS "$\"\'"

# define M_GLUED_OPERATOR "Syntax Error ! : 2 OPERATEUR A LA SUITE :"
# define M_DOUBLE_OPERATOR "parse error near : "
# define M_OPERATOR_IN_IDENTIFIER "no matches found : "
# define M_NO_END "Syntax Error (code 4) !" // jsp pour linstant
# define M_CMD_NOT_FOUND "command not found : "
# define M_NOT_ENOUGH_ARG "Not enough arguments : "

#endif