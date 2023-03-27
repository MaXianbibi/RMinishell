/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmorneau <jmorneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 19:44:24 by justinmorne       #+#    #+#             */
/*   Updated: 2023/03/27 14:13:18 by jmorneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

t_global global;

void signal_handler(int n)
{
	if (n == SIGINT)
	{
		write(2, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 1);
		rl_redisplay();
	}
}

// *((int*)global.head_env + 7) = 0b1111111111111111111111111111111;
// printf("%s %p %d\n",global.head_env->str, global.head_env->next, *((int*)global.head_env + 7));  // OK
static void init_list_env(void)
{
	int i;
	t_env *tmp;

	i = 0;
	while (global.env[i])
	{
		tmp = (t_env *)creat_new_node();
		insert_at_head((t_lexer **)&global.head_env, (t_lexer *)tmp);
		if (ft_strnstr(global.env[i], "SHLVL=", 6))
			global.env[i][6] = ft_atoi(global.env[i] + 6) + 1 + '0'; // peut prendre jusqua 9 max / a voir si je gère
		tmp->str = ft_strdup(global.env[i]);
		i++;
	}
}

static void data_init(char **env)
{
	ft_memset(&global, 0, sizeof(global));
	global.terminal = open("/dev/tty", O_RDONLY);
	global.std_out = dup(STDOUT_FILENO);
	if (env)
		global.env = env;
	init_list_env();
}

static int minishell(void)
{
	dup2(global.terminal, STDIN_FILENO);
	dup2(global.std_out, STDOUT_FILENO);
	global.fd_out = global.std_out;
	global.cmd = readline("> ");
	if (!global.cmd)
		ft_exit(NULL);
	pipe(global.fd_in);
	if (!ft_lexer(global.cmd))
		return (0);
	add_history(global.cmd);
	if (!ft_parser())
		return (0);
	if (!ft_execute())
		return (0);
	return (0);
}

int main(int argc, char **argv, char **env)
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