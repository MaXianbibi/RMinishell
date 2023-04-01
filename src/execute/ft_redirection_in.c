/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirection_in.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:13 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/31 19:53:46 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	check_file(char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
	{
		perror("Error ");
		close(fd);
		return (0);
	}
	return (fd);
}

static int	stupid_norm_d(char *stop, int buffer_size, char *buffer, int fd)
{
	char	*s;

	s = readline("heredoc>");
	if (!s)
		return (SUCCESS);
	while (ft_strncmp(s, stop, 8192))
	{
		if (buffer_size + ft_strlen(s) > 8192)
		{
			printf("Buffer size overflow\n");
			break ;
		}
		ft_strlcpy(buffer + buffer_size, s, 8192);
		buffer_size += ft_strlen(s);
		buffer[buffer_size] = '\n';
		buffer_size++;
		free(s);
		s = readline("heredoc>");
		if (!s)
			break ;
	}
	ft_putstr_fd(buffer, fd);
	return (0);
}

int static	delimiter(t_lexer *tmp)
{
	char	buffer[8192];
	char	*stop;
	int		fd;

	ft_memset(buffer, 0, 8192);
	fd = STDOUT_FILENO;
	if (!tmp->next)
		return (0);
	tmp = tmp->next;
	stop = tmp->identifier;
	if (tmp->next)
		fd = check_file_out(tmp->next);
	if (fd == 0)
		return (0);
	stupid_norm_d(stop, 0, buffer, fd);
	return (0);
}

int	ft_redirection(t_lexer *tmp)
{
	if (!tmp->next)
		return (FAIL);
	if (tmp->identifier[1] && tmp->identifier[1] == '<')
		return (delimiter(tmp));
	else
	{
		tmp = tmp->next;
		tmp->token = OPERATOR;
		g_global.fd_in[1] = check_file(tmp->identifier);
		if (!g_global.fd_in[1])
			return (0);
		if (dup2(g_global.fd_in[1], STDIN_FILENO) == -1)
			return (0);
		close(g_global.fd_in[1]);
	}
	return (SUCCESS);
}
