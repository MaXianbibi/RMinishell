/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:51:50 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/10 22:02:52 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;


int ft_search_c(const char * str, int c)
{
	int i;
	
	i = 0;
	while (str[i] && str[i] != c)
	{
		if (str[i] == '\'' || str[i] == '\"')
			c = str[i];	
		i++;
	}
	if (str[i] && (c == '\'' || c == '\"') && str[i] == c)
		i++;
	// if (!str[i] && c != ' ')
		// return (-1);
	return (i);
}

char *ft_len_token(const char * str, int * index)
{
	int i;
	char * tmp;


	i = ft_search_c(str, ' ');
	tmp = ft_substr(str, 0, i);

	*index += i;
	return (tmp);
}

char * ft_word(const char * str, int * index)
{
	int i;
	char * tmp;
	
	i = ft_search_c(str + 1, str[0]);
	if (i == -1)	
		return (NULL);
	i += 2;
		
	tmp = ft_substr(str, 0, i);	
	*index += i;
	return (tmp);
	
}

static int ft_split_lexer(const char * str)
{
	t_lexer * tmp;
	int i;

	i = 0;
	while (str[i])
	{
		if(str[i] == ' ')
			i++;
		else
		{
			tmp = creat_new_node();
			insert_at_head(&global.head_lexer, tmp);
			if (str[i] == '\"' || str[i] == '\'')
			{
				tmp->identifier = ft_word(str + i, &i);	
				if (!tmp->identifier)
					return (print_error(NO_END));
				tmp->token = ARG;
			}
			else
				tmp->identifier = ft_len_token(str + i, &i);
		}
	}
	return (1);
}

int ft_lexer(const char * str)
{
    t_lexer *tmp;

    if (!str)
        return (0);
	if (!ft_split_lexer(str))
		return (0);
	if (!global.head_lexer)
		return (0);
	tmp = global.head_lexer;
	while (tmp)
	{
		if (ft_strchr(OPERATORS, tmp->identifier[0]))
			tmp->token = OPERATOR;
		else if (ft_strchr(VAR_OPERATORS, tmp->identifier[0]))
			tmp->token = VAR;
		else
			tmp->token = IDENTIFIER;
		tmp = tmp->next;
	}
    return (1);
}