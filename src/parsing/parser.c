/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 23:04:44 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/05 20:37:50 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	double_operator(void)
{
	t_lexer	*tmp;
	int		i;

	tmp = g_global.head_lexer;
	i = 1;
	if (tmp->token == OPERATOR && (tmp->identifier[0] == '<'
			|| tmp->identifier[0] == '>'))
		i = 0;
	while (tmp)
	{
		if (tmp->token == OPERATOR)
			i++;
		else
			i = 0;
		if (i > 1)
		{
			g_global.error = tmp->identifier;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

static int	identifier_parsing(void)
{
	t_lexer	*tmp;
	int		i;

	tmp = g_global.head_lexer;
	while (tmp)
	{
		i = 0;
		if (tmp->token == IDENTIFIER || tmp->token == ARG)
		{
			while (tmp->identifier[i])
			{
				if (ft_strchr(OPERATORS, tmp->identifier[i]))
				{
					g_global.error = tmp->identifier;
					return (0);
				}
				i++;
			}
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_parse_token(void)
{
	t_lexer	*tmp;

	tmp = g_global.head_lexer;
	while (tmp)
	{
		if (tmp->identifier[0] && (tmp->token == IDENTIFIER || (!tmp->next
					&& ft_strchr(OPERATORS, tmp->identifier[0]))))
		{
			g_global.error = tmp->identifier;
			return (FAIL);
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}

static int	pipe_init(void)
{
	t_lexer	*tmp;
	int		size;
	int		i;

	i = 0;
	size = 0;
	tmp = g_global.head_lexer;
	while (tmp)
	{
		if (tmp->token == OPERATOR && tmp->identifier[0] == '|'
			&& tmp->identifier[1] == '\0')
			size++;
		tmp = tmp->next;
	}
	g_global.pipe_tab = ft_calloc(sizeof(int *), size + 1);
	while (i < size)
	{
		g_global.pipe_tab[i] = calloc(sizeof(int), 2);
		if (pipe(g_global.pipe_tab[i++]) == -1)
		{
			perror("ERROR ");
			return (FAIL);
		}
	}
	return (SUCCESS);
}

int	ft_parser(void)
{
	if (!double_operator())
		return (print_error(DOUBLE_OPERATOR));
	if (!identifier_parsing())
		return (print_error(OPERATOR_IN_IDENTIFIER));
	ft_parse_quotes();
	if (!ft_parse_operator())
		return (0);
	pipe_init();
	parsing_cmd();
	return (1);
}
