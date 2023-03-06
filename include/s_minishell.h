/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:48:31 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/05 22:15:29 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_MINISHELL_H
# define S_MINISHELL_H

struct s_lexer
{
	struct s_lexer	*next;
	union 
	{
		char				*identifier;
		struct s_lexer 		* (*ptr)(struct s_lexer * );
	};
	int				token;
};
typedef struct s_lexer t_lexer;

struct s_env
{
	struct s_env	*next;
	const char 		*str;
};
typedef struct s_env t_env;

struct s_global
{
	t_lexer 	*		head_lexer;
	char 		** 		env;
	char 		*		error;
	char		*		cmd;
	t_env		*		head_env;
};
typedef struct s_global	t_global;

enum	e_token
{
    IDENTIFIER,
    OPERATOR,
	CMD,
	ARG,
	VAR,
	BUILTIN
};

enum	e_error
{
    GLUED_OPERATOR,
	DOUBLE_OPERATOR,
	OPERATOR_IN_IDENTIFIER,
	NO_END,
	CMD_NOT_FOUND
};

enum	e_builtins
{
	ECHO,
	CD,
	PWD,
	EXPORT,
	UNSET,
	ENV,
	EXIT
};


#endif