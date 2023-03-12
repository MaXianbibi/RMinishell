/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_in.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:13 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/11 19:09:28 by jmorneau         ###   ########.fr       */
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

	tmp = tmp->next;
	tmp->token = OPERATOR;
	s = readline("heredoc>");
	while (ft_strncmp(s, tmp->identifier, 1024))
	{
		s = ft_strjoin(s, "\n");
		ft_putstr_fd(s, global.fd_in[1]);
		free(s);
		s = readline("heredoc>");
	}
	close(global.fd_in[1]);
	dup2(global.fd_in[0], STDIN_FILENO);
	close(global.fd_in[0]);
	return (SUCCESS);
}

int ft_redirection(t_lexer *tmp)
{
	if (!tmp->next)
		return (FAIL);
	if (tmp->identifier[1] && tmp->identifier[1] == '<')
		delimiter(tmp);
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