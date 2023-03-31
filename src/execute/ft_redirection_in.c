/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_in.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: justinmorneau <justinmorneau@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:13 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/28 22:51:05 by justinmorne      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

extern t_global global;

static int check_file(char *str)
{
	int fd;

	fd = open(str, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		perror("Error ");
		close(fd);
		return (0);
	}
	return (fd);
}

int static delimiter(t_lexer *tmp)
{
	char * s;
	char * stop;
	int fd;

	
	fd = STDOUT_FILENO;
	if (!tmp->next)
		return (0);
	
	tmp = tmp->next;
	stop = tmp->identifier;
	
	if (tmp->next)
		fd = check_file_out(tmp->next->next);
	if (fd == 0)
		return (0);
	s = readline("heredoc>");
	if (!s)
		return (SUCCESS);
	while (ft_strncmp(s, tmp->identifier, 1024))
	{
		s = ft_strjoin(s, "\n");
		ft_putstr_fd(s, fd);
		free(s);
		s = readline("heredoc>");
		if (!s)
			break ;
	}
	return (0);
}

int ft_redirection(t_lexer *tmp)
{
	if (!tmp->next)
		return (FAIL);
	if (tmp->identifier[1] && tmp->identifier[1] == '<')
		return (delimiter(tmp));
	else
	{
		tmp = tmp->next;
		tmp->token = OPERATOR;
		global.fd_in[1] = check_file(tmp->identifier);
		if (!global.fd_in[1])
			return (0);
		if (dup2(global.fd_in[1], STDIN_FILENO) == -1)
			return (0);
		close(global.fd_in[1]);
	}
	return (SUCCESS);
}