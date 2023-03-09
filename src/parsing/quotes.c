/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 17:48:28 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/08 20:30:45 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

static char *ft_strldup(const char *str, int n)
{
	char *tmp;
	int size;

	size = ft_strlen(str);
	if (size < n)
		tmp = calloc(size + 1, sizeof(char));
	else
		tmp = calloc(n + 1, sizeof(char));

	ft_strlcpy(tmp, str, n);

	return (tmp);
}

char * remove_single_quotes( char * str)
{
	char * tmp;

	tmp = ft_strldup(str + 1 ,ft_strlen(str) - 1);
	
	free(str);
	return ( tmp );
	
}

static char * add_single_quote (char * str)
{
	char * tmp;
	int size;

	size = ft_strlen(str);
	tmp = ft_calloc(ft_strlen(str) + 3, 1);
	tmp[0] = '\'';
	ft_strlcpy(tmp + 1, str, 1024);
	tmp[size + 1] = '\'';
	free(str);
	return (tmp);
}
static char * add_space (char * str)
{
	char * tmp;

	tmp = ft_strjoin(str, " ");
	free(str);
	return (tmp);
}

char *multiple_join(char **split)
{
	int i;
	char *tmp;
	char *str;

	i = 0;
	tmp = NULL;
	str = NULL;
	while (split[i])
	{
		if (str)
		{
			free(str);
			str = NULL;
		}
		str = ft_strjoin(tmp, split[i]);
		if (split[i + 1])
			str = add_space(str);		
		if (tmp)
		{
			free(tmp);
			tmp = NULL;
		}
		tmp = ft_strdup(str);
		i++;
	}
	if (tmp)
		free(tmp);
	return (str);
}

int ft_parse_quotes(void)
{
	t_lexer *tmp;
	t_env *tmp_env;
	char *var;
	char **split_var;
	int i;
	int isin;

	isin = 0;
	i = 0;
	tmp = global.head_lexer;
	tmp_env = NULL;
	while (tmp)
	{
		if (tmp->token == VAR)
		{
			if (tmp->identifier[0] == '$')
			{
				if (tmp->identifier[1])
				{
					tmp_env = check_list(tmp->identifier + 1);
					free(tmp->identifier);
					if (tmp_env)
						tmp->identifier = ft_strdup(ft_strchr(tmp_env->str, '=') + 1);
					else
						tmp->identifier = ft_strdup("");
				}
			}
			else if (tmp->identifier[0] == '\"')
			{
				var = ft_strldup(tmp->identifier + 1, ft_strlen(tmp->identifier) - 1); // a free :)
				free(tmp->identifier);
				if (ft_strchr(var, '$'))
				{
					split_var = ft_split(var, ' ');
					free(var);
					while (split_var[i])
					{
						if (split_var[i][0] == '\'' && ft_strchr(split_var[i], '$'))
						{
							isin = 1;
							split_var[i] = remove_single_quotes(split_var[i]);
							
						}
						if (ft_strchr(split_var[i], '$'))
						{
							if (split_var[i][0] == '$' || split_var[i][0] == '\'')
							{
								if (split_var[i][1])
								{
									tmp_env = check_list(split_var[i] + 1);
									free(split_var[i]);
									if (tmp_env)
										split_var[i] = ft_strdup(ft_strchr(tmp_env->str, '=') + 1);
									else
										split_var[i] = ft_strdup("");
								}
							}
							else
								split_var[i][ft_find_index(split_var[i], '$')] = '\0';
							if (isin == 1)
							{
								isin = 0;
								split_var[i] = add_single_quote(split_var[i]);
							}
						}
						i++;
					}
					var = multiple_join(split_var);
					ft_free_chartable(split_var);
				}
				tmp->identifier = var;
			}
			else if (tmp->identifier[0] == '\'')
			{
				var = ft_strldup(tmp->identifier + 1, ft_strlen(tmp->identifier) - 1);
				free(tmp->identifier);
				tmp->identifier = var;
			}
			tmp->token = IDENTIFIER;
		}
		tmp = tmp->next;
	}
	return (SUCCESS);
}