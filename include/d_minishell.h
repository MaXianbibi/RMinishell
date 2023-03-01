/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:47:16 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/01 13:39:53 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef D_MINISHELL_H
# define D_MINISHELL_H

#include <stdio.h>

#define OPERATORS "|&;<>()$`\\\"\'*?[#˜=%"

# define M_GLUED_OPERATOR "Syntax Error (code 0) !"
# define M_DOUBLE_OPERATOR "Syntax Error (code 1) !"
# define M_OPERATOR_IN_IDENTIFIER "Syntax Error (code 3) !"

#endif