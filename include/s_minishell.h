/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:48:31 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/02 22:53:04 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MINISHELL_H
# define S_MINISHELL_H

struct s_lexer
{
	struct s_lexer	*next;
	struct s_lexer	*previous;
	union 
	{
		char			*identifier;
		char			operator;
	};
	int				token;
};
typedef struct s_lexer t_lexer;

struct s_global
{
	t_lexer *		head_lexer;
	char ** 		env;
	char *			error;
};
typedef struct s_global	t_global;

enum	e_token
{
    IDENTIFIER,
    OPERATOR,
	CMD,
	ARG,
	VAR
};

enum	e_error
{
    GLUED_OPERATOR,
	DOUBLE_OPERATOR,
	OPERATOR_IN_IDENTIFIER,
	NO_END
};




#endif