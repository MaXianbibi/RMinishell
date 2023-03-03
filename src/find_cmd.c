/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 10:28:48 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/03 16:58:56 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

char	*find_path_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != 0)
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

static char	*find_path(char **path, char *cmd)
{
	int		i;
	char	*tmp;

	i = 0;
	while (cmd != NULL && path[i] != NULL)
	{
		tmp = ft_strjoin(path[i], cmd);
		if (access(tmp, F_OK) == 0)
			return (tmp);
		free(tmp);
		i++;
	}
	return (NULL);
}

char	*find(char **envp, char *cmd)
{
	char	**path_env;
	char	*tmp;
	char	*path_to_command;
	int		i;

	i = 0;
	path_env = ft_split(find_path_line(envp), ':');
	while (path_env[i] != NULL)
	{
		tmp = ft_strjoin(path_env[i], "/");
		free(path_env[i]);
		path_env[i] = tmp;
		i++;
	}
	path_to_command = find_path(path_env, cmd);
	if (!path_to_command)
	{
		ft_free_chartable(path_env);
		return (0);
	}
	ft_free_chartable(path_env);
	return (path_to_command);
}

static void ptr_builtin(t_lexer * cmd, int i)
{
	free(cmd->identifier);
	if (i == ECHO)
		cmd->ptr = &ft_echo;

	cmd->token = BUILTIN;
}

int find_builtins(t_lexer * cmd)
{
	static char * list[10] = {"echo", "cd", "pwd", "export",
								 "unset", "env", "exit"};
	char * tmp;
	int i;

	i = 0;
	tmp = strdup(cmd->identifier);
	lowercase_str(tmp);	
	
	while (i < 7)
	{
		if (!ft_strncmp(tmp, list[i], 100))
		{
			ptr_builtin(cmd, i);
			free(tmp);
			return (1);
		}
		i++;
	}
	free(tmp);
	return (0);
}
