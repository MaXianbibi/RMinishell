/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_minishell.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 16:48:41 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/03 16:45:12 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_MINISHELL_H
# define P_MINISHELL_H

#include "s_minishell.h"

int        ft_lexer(const char * str);
void	    insert_at_head(t_lexer **head, t_lexer *node_to_insert);
t_lexer	    *creat_new_node();
void        freehead(t_lexer *head);
int         ft_parser( void );
int         print_error(int code_error);
char		*find(char **envp, char *cmd);
void		lowercase_str(char * str);
int			find_builtins(t_lexer * cmd);

int			ft_echo( t_lexer * tmp);


#endif