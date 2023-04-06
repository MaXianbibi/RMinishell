/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   double_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 08:01:41 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/05 18:56:55 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*remove_single_quotes(char *str)
{
	char	*tmp;

	tmp = ft_strldup(str + 1, ft_strlen(str) - 1);
	free(str);
	return (tmp);
}

static char	*add_c(char *str, char c)
{
	char	*tmp;
	int		size;

	size = ft_strlen(str);
	tmp = ft_calloc(ft_strlen(str) + 3, 1);
	tmp[0] = c;
	ft_strlcpy(tmp + 1, str, 1024);
	tmp[size + 1] = c;
	free(str);
	return (tmp);
}

void	norminette_double_quotes(char **split_var, int i, char *var)
{
	if (ft_strchr(split_var[i], '$'))
	{
		if (split_var[i][0] == '\'')
		{
			split_var[i] = remove_single_quotes(split_var[i]);
			var = env_var(split_var[i]);
			free(split_var[i]);
			split_var[i] = add_c(var, '\'');
		}
		else
		{
			var = env_var(split_var[i]);
			free(split_var[i]);
			split_var[i] = var;
		}
	}
}

char	*double_quotes(t_lexer *tmp)
{
	char	*var;
	char	**split_var;
	int		i;

	i = 0;
	split_var = NULL;
	var = ft_strldup(tmp->identifier + 1, ft_strlen(tmp->identifier) - 1);
	if (ft_strchr(var, '$'))
	{
		split_var = ft_split(var, ' ');
		free(var);
		while (split_var[i])
		{
			norminette_double_quotes(split_var, i, var);
			i++;
		}
		var = multiple_join(split_var, 1);
		ft_free_chartable(split_var);
	}
	return (var);
}
