/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:48:41 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/05 22:02:35 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MINISHELL_H
# define P_MINISHELL_H

#include "s_minishell.h"

int        ft_lexer(const char * str);
void	    insert_at_head(t_lexer **head, t_lexer *node_to_insert);
t_lexer	    *creat_new_node();
void        freehead();
int         ft_parser( void );
int         print_error(int code_error);
char		*find(char **envp, char *cmd);
void		lowercase_str(char * str);
int			find_builtins(t_lexer * cmd);

// EXEC

int ft_execute( void );

// BUILTS IN

t_lexer *	ft_echo( t_lexer * tmp);
t_lexer     *ft_exit(t_lexer *tmp);
t_lexer *   ft_pwd( t_lexer * tmp);

#endif