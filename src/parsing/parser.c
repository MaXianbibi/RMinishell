/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:04:44 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/11 17:36:58 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

static int double_operator(void)
{
	t_lexer *tmp;
	int i;

	tmp = global.head_lexer;

	i = 1;
	if (tmp->token == OPERATOR && (tmp->identifier[0] == '<' || tmp->identifier[0] == '>'))
		i = 0;
	while (tmp)
	{
		if (tmp->token == OPERATOR)
			i++;
		else
			i = 0;
		if (i > 1)
		{
			global.error = tmp->identifier;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

static int identifier_parsing(void)
{
	t_lexer *tmp;
	int i;

	tmp = global.head_lexer;
	while (tmp)
	{
		i = 0;
		if (tmp->token == IDENTIFIER || tmp->token == ARG)
		{
			while (tmp->identifier[i])
			{
				if (ft_strchr(OPERATORS, tmp->identifier[i]))
				{
					global.error = tmp->identifier;
					return (0);
				}
				i++;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

void parsing_cmd(void)
{
	t_lexer *tmp;
	char *str;

	tmp = global.head_lexer;
	while (tmp)
	{
		if (tmp->token == IDENTIFIER)
		{
			if (find_builtins(tmp))
				continue;
			else if ((tmp->identifier[0] == '.' || tmp->identifier[0] == '/' ) && !access(tmp->identifier, X_OK))
				tmp->token = CMD;
			else if (*global.env)
			{
				str = find(global.env, tmp->identifier);
				if (str)
				{
					free(tmp->identifier);
					tmp->identifier = str;
					tmp->token = CMD;
				}
				tmp->token = CMD;
			}
		}
		tmp = tmp->next;
		while (tmp && tmp->token != OPERATOR)
		{
			tmp->token = ARG;
			tmp = tmp->next;
		}
		if (tmp)
			tmp = tmp->next;
	}
}

int ft_parse_token ( void )
{
	t_lexer * tmp;

	tmp = global.head_lexer;
	while (tmp)
	{
		if (tmp->token == IDENTIFIER || (!tmp->next && tmp->token == OPERATOR))
		{
			global.error = tmp->identifier;
			return (FAIL);
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

static int pipe_init( void )
{
	t_lexer * tmp;
	int size;
	int i;

	i = 0;
	size = 0;
	tmp = global.head_lexer;
	while (tmp)
	{
		if (tmp->token == OPERATOR && tmp->identifier[0] == '|' && tmp->identifier[1] == '\0')
			size++;
		tmp = tmp->next;
	}
	global.pipe_tab = ft_calloc(sizeof(int *), size + 1);
	while (i < size)
	{
		global.pipe_tab[i] = calloc(sizeof(int), 2);
		if (pipe(global.pipe_tab[i]) == -1)
		{
			perror("ERROR ");
			return (FAIL);
		}
		i++;
	}
	return (SUCCESS);
}

int ft_parser(void)
{
	if (!double_operator())
		return (print_error(DOUBLE_OPERATOR));
	if (!identifier_parsing())
		return (print_error(OPERATOR_IN_IDENTIFIER));
	ft_parse_quotes();
	if (!ft_parse_operator())
		return (0);
	pipe_init();
	parsing_cmd(); // remplace les caractères originel par les cmd (si trouvé)
	if (!ft_parse_token())
		return (print_error(CMD_NOT_FOUND));
		
	return (1);
}