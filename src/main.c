/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:35:16 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 15:35:19 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	valid_flag(const char *str)
{
	size_t		i;
	t_string	flag;

	i = 0;
	while (str[i])
	{
		if (str[i] != 'c')
		{
			flag = ft_str_new(NULL);
			ft_str_add_back(flag, '-');
			ft_str_add_back(flag, str[i]);
			str = ft_str_data(flag);
			pset_err(SHELL_NAME, str, INVALID_OPTION, GENERIC_ERR);
			ft_str_free(flag);
			return (false);
		}
		++i;
	}
	return (true);
}

static const char	*get_cmd(char *const *argv)
{
	size_t	i;

	i = 1;
	while (argv[i] && argv[i][0] == '-')
	{
		if (!valid_flag(&argv[i][1]))
			return (NULL);
		++i;
	}
	if (!argv[i])
		pset_err(SHELL_NAME, "-c", C_FLAG_ARG_REQ, GENERIC_ERR);
	return (argv[i]);
}

static void	execute_cmd(const char *cmd)
{
	t_tokenizer	tok;
	t_list		*tokens;
	t_node		*cmds;

	if (!cmd)
		return ;
	if (!*cmd)
		return ;
	init_tokenizer(&tok);
	tok.str = (char *)cmd;
	tokens = tokenize(&tok);
	cmds = parse(tokens);
	process_cmd(cmds);
	ft_lstclear(&tokens, ft_str_free);
	nodeclear(&cmds);
}

int	main(int argc, char **argv, char **envp)
{
	minishell_init(envp);
	if (argc > 1 && argv[1][0] == '-')
		execute_cmd(get_cmd(argv));
	else if (argc > 1)
		pset_err(SHELL_NAME, argv[1], UNSUPPORTED_ARG, GENERIC_ERR);
	else
	{
		minishell_loop();
		ft_putendl_fd("exit", STDOUT_FILENO);
	}
	minishell_destroy();
	return ((int)g_mini.code);
}
