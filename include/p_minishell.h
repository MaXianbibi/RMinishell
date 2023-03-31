/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:48:41 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/28 22:28:56 by justinmorne      ###   ########.fr       */
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
int         ft_search_c(const char * str, int c);
int         ft_redirection( t_lexer * tmp);
int         ft_parse_operator( void );
int         ft_redirection_out( t_lexer * tmp);
char 		*env_var(char * tmp);
char * 		double_quotes(t_lexer *tmp);
int	        check_file_out(t_lexer * tmp);


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