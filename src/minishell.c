/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:44:24 by justinmorne       #+#    #+#             */
/*   Updated: 2023/04/02 14:33:10 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_global	g_global;

void	signal_handler(int n)
{
	if (n == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

static void	init_list_env(void)
{
	int		i;
	t_env	*tmp;

	i = 0;
	while (g_global.env[i])
	{
		tmp = (t_env *)creat_new_node();
		insert_at_head((t_lexer **)&g_global.head_env, (t_lexer *)tmp);
		if (ft_strnstr(g_global.env[i], "SHLVL=", 6))
			g_global.env[i][6] = ft_atoi(g_global.env[i] + 6) + 1 + '0';
		tmp->str = ft_strdup(g_global.env[i]);
		i++;
	}
}

static void	data_init(char **env)
{
	ft_memset(&g_global, 0, sizeof(g_global));
	g_global.terminal = open("/dev/tty", O_RDONLY);
	g_global.std_out = dup(STDOUT_FILENO);
	g_global.last_cmd = ft_calloc(sizeof(t_env), 1);
	g_global.last_cmd->str = ft_strdup("0");
	if (env)
		g_global.env = env;
	init_list_env();
}

static int	minishell(void)
{
	dup2(g_global.terminal, STDIN_FILENO);
	dup2(g_global.std_out, STDOUT_FILENO);
	g_global.fd_out = g_global.std_out;
	g_global.cmd = readline("> ");
	if (!g_global.cmd)
		ft_exit(NULL);
	pipe(g_global.fd_in);
	if (!ft_lexer(g_global.cmd))
		return (0);
	add_history(g_global.cmd);
	if (!ft_parser())
		return (0);
	if (!ft_execute())
		return (0);
	return (0);
}

int	main(int argc, char **argv, char **env)
{
	printf("MINISHELL : \n");
	(void)argc;
	(void)argv;
	signal(SIGINT, signal_handler);
	signal(SIGTSTP, SIG_IGN);
	data_init(env);
	while (1)
	{
		minishell();
		freehead();
	}
}
