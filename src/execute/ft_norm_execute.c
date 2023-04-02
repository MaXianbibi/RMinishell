/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_execute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:25:32 by jmorneau          #+#    #+#             */
/*   Updated: 2023/04/02 10:59:20 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_trim(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == '/')
		{
			i++;
			break ;
		}
		i--;
	}
	if (i > 0)
		return (str + i);
	return (str);
}

static int	ft_execve(char *path_to_cmd, char **arg)
{
	char	**child_env;

	child_env = convert_env();
	if (execve(path_to_cmd, arg, child_env) == -1)
	{
		perror("ERROR ");
		exit(1);
	}
	exit(0);
}

t_lexer	*ft_execute_cmd(t_lexer *tmp)
{
	char	*arg[1024];
	char	*path_to_cmd;
	int		i;

	i = 1;
	ft_memset(arg, 0, sizeof(arg));
	path_to_cmd = tmp->identifier;
	arg[0] = ft_trim(tmp->identifier);
	tmp = tmp->next;
	while (tmp && (tmp->token == IDENTIFIER || tmp->token == ARG
			|| tmp->token == VAR) && i < 1024)
	{
		arg[i] = tmp->identifier;
		tmp = tmp->next;
		i++;
	}
	if (arg[0][0])
		ft_execve(path_to_cmd, arg);
	return (tmp);
}

void	ft_execute_env(t_lexer *tmp, pid_t *id, int *res)
{
	int	i;

	i = 0;
	while (tmp)
	{
		if (tmp->token == CMD || (tmp->token == BUILTIN && *g_global.pipe_tab))
		{
			*id = fork();
			if (*id == 0)
				stupid_norm(i, tmp);
			i++;
		}
		else if (tmp->token == BUILTIN)
		{
			if (tmp->ptr(tmp))
				*res = 1;
			else
				*res = 0;
		}
		tmp = tmp->next;
	}
}
