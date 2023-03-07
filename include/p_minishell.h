/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:48:41 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/07 18:06:25 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MINISHELL_H
# define P_MINISHELL_H

#include "s_minishell.h"

int         ft_lexer(const char * str);
void	    insert_at_head(t_lexer **head, t_lexer *node_to_insert);
t_lexer	    *creat_new_node();
void        freehead();
int         ft_parser( void );
int         print_error(int code_error);
char		*find(char **envp, char *cmd);
void		lowercase_str(char * str);
int			find_builtins(t_lexer * cmd);
t_env *     check_list( const char * str );
char 	** 	convert_env( void );
int 		ft_parse_quotes ( void );


// EXEC

int ft_execute( void );

// BUILTS IN

t_lexer *	ft_echo( t_lexer * tmp);
t_lexer *   ft_exit(t_lexer *tmp);
t_lexer *   ft_pwd( t_lexer * tmp);
t_lexer *   ft_env( t_lexer * tmp );
t_lexer   * ft_cd(t_lexer *tmp);
t_lexer *   ft_export( t_lexer * tmp );
t_lexer *   ft_unset(t_lexer *tmp);

#endif