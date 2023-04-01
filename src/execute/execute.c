/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:22:09 by jmorneau          #+#    #+#             */
/*   Updated: 2023/03/31 19:47:46 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static void	dup_pipe(int i)
{
	int	j;

	j = 0;
	if (i != 0)
		dup2(g_global.pipe_tab[i - 1][0], STDIN_FILENO);
	if (i != size_of_tab(g_global.pipe_tab))
		dup2(g_global.pipe_tab[i][1], STDOUT_FILENO);
	else
		dup2(g_global.fd_out, STDOUT_FILENO);
	while (j < size_of_tab(g_global.pipe_tab))
	{
		close(g_global.pipe_tab[j][0]);
		close(g_global.pipe_tab[j][1]);
		j++;
	}
}

void	stupid_norm(int i, t_lexer *tmp)
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

int	ft_execute(void)
{
	t_lexer	*tmp;
	pid_t	id;
	int		i;
	int		res;

	tmp = g_global.head_lexer;
	res = 0;
	id = 0;
	i = 0;
	ft_execute_env(tmp, &id, &res);
	while (g_global.pipe_tab[i])
	{
		close(g_global.pipe_tab[i][0]);
		close(g_global.pipe_tab[i][1]);
		i++;
	}
	while (i-- > 0)
		waitpid(id, &res, 0);
	waitpid(id, &res, 0);
	g_global.last_cmd.str = ft_itoa(res);
	return (1);
}
