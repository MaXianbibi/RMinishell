/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:22:09 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/27 14:18:03 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

static char *ft_trim(char *str)
{
	int i;

	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == '/')
		{
			i++;
			break;
		}
		i--;
	}
	if (i > 0)
		return (str + i);
	else
		return (str);
}

static int ft_execve(char *path_to_cmd, char **arg)
{
	char **child_env;

	child_env = convert_env();
	if (execve(path_to_cmd, arg, child_env) == -1)
	{
		perror("ERROR ");
		exit(1);
	}
	exit(0);
}

static t_lexer *ft_execute_cmd(t_lexer *tmp)
{
	char *arg[50];
	char *path_to_cmd;
	int i;

	i = 1;
	ft_memset(arg, 0, sizeof(arg));
	path_to_cmd = tmp->identifier;
	arg[0] = ft_trim(tmp->identifier);
	tmp = tmp->next;
	while (tmp && (tmp->token == IDENTIFIER || tmp->token == ARG || tmp->token == VAR))
	{
		arg[i] = tmp->identifier;
		tmp = tmp->next;
		i++;
	}
	if (arg[0][0])
		ft_execve(path_to_cmd, arg);
	return (tmp);
}

static int size_of_tab(int **tab)
{
	int i;

	i = 0;
	while (tab[i])
		i++;

	return (i);
}

static void dup_pipe(int i)
{
	int j;

	j = 0;
	if (i != 0)
		dup2(global.pipe_tab[i - 1][0], STDIN_FILENO);
	if (i != size_of_tab(global.pipe_tab))
		dup2(global.pipe_tab[i][1], STDOUT_FILENO);
	else
		dup2(global.fd_out, STDOUT_FILENO);
	while (j < size_of_tab(global.pipe_tab))
	{
		close(global.pipe_tab[j][0]);
		close(global.pipe_tab[j][1]);
		j++;
	}
}

int ft_execute(void)
{
	t_lexer *tmp;
	pid_t id;
	tmp = global.head_lexer;
	int i;
	int res;

	i = 0;
	while (tmp)
	{
		if (tmp->token == CMD || (tmp->token == BUILTIN && *global.pipe_tab))
		{
			id = fork();
			if (id == 0)
			{
				signal(SIGINT, SIG_DFL);
    			signal(SIGQUIT, SIG_DFL);
    			signal(SIGTSTP, SIG_DFL);
				dup_pipe(i);
				if (tmp->token == CMD)
					ft_execute_cmd(tmp);
				else
				{
					if (tmp->ptr(tmp))
						exit(1);
					exit(0);
				}
			}
			i++;
		}
		else if (tmp->token == BUILTIN)
			tmp->ptr(tmp);
		tmp = tmp->next;
	}
	i = 0;
	while (global.pipe_tab[i])
	{
		close(global.pipe_tab[i][0]);
		close(global.pipe_tab[i][1]);
		i++;
	}
	while (i-- > 0)
		waitpid(id, NULL, 0);
	waitpid(id, &res, 0);
	global.last_cmd = atoi(res)
	return (1);
}
