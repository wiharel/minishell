/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wiharel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 15:48:19 by wiharel           #+#    #+#             */
/*   Updated: 2022/12/15 16:22:05 by wiharel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <string.h>
# include <sys/errno.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <readline/readline.h>
# include <fcntl.h>
# include <libft/libft.h>
# include <stdbool.h>
# include <unistd.h>
# include <readline/history.h>
# include <linux/limits.h>
# include <stdint.h>
# include <termios.h>

# define OP ">|<"

# define SHELL_NAME "minishell"

# define SUCCESS 0
# define GENERIC_ERR 1
# define SYNTAX_ERR 2
# define NOT_EXEC_ERR 126
# define ENVIRONMENT_ERR 127
# define INTERRUPT_SIG 130
# define QUIT_SIG 131

# define BAD_IDENT "not a valid identifier"
# define TOO_MANY_ARGS "too many arguments"
# define NUMERIC_REQ "numeric argument required"
# define CMD_NOT_FOUND "command not found"
# define NO_HOME "HOME not set"
# define UNCLOSED_QUOTES "found unclosed quotes"
# define UNCLOSED_DQUOTES "found unclosed double quotes"
# define WARNING "warning"
# define HEREDOC_EOF "here-document was delimited by end-of-file"
# define C_FLAG_ARG_REQ "option requires an argument"
# define INVALID_OPTION "invalid option"
# define UNSUPPORTED_ARG "unsupported argument"

# define ENV_PWD "PWD"
# define ENV_OLDPWD "OLDPWD"
# define ENV_HOME "HOME"
# define ENV_USER "USER"
# define ENV_PATH "PATH"

# define FT_ECHO "echo"
# define FT_PWD "pwd"
# define FT_CD "cd"
# define FT_EXPORT "export"
# define FT_UNSET "unset"
# define FT_ENV "env"
# define FT_EXIT "exit"

typedef struct s_minishell
{
	struct termios	term;
	int				stdin_fd;
	int				stdout_fd;
	char			**envp;
	char			*user;
	uint32_t		code;

}	t_minishell;

typedef enum e_state
{
	TEXT,
	QUOTE,
	DQUOTE,
}	t_state;

typedef struct s_tokenizer
{
	char			*str;
	unsigned int	cursor;
	t_state			state;
	t_string		next_token;
}	t_tokenizer;

typedef enum e_type
{
	PIPE,
	OUTPUT,
	APPEND,
	INPUT,
	HEREDOC,
	STRING,
}	t_type;

typedef struct s_redir
{
	t_type	type;
	char	*file;
}	t_redir;

typedef struct s_node
{
	char			**argv;
	t_list			*redirs;
	int				fd[2];
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

extern t_minishell	g_mini;
typedef void		(*t_builtin)(t_node *);

t_builtin	builtin_ptr(const char *str);
void		ft_echo(t_node *node);
void		ft_cd(t_node *node);
void		ft_unset(t_node *node);
void		ft_export(t_node *node);
void		ft_pwd(t_node *node);
void		ft_env(t_node *node);
void		ft_exit(t_node *node);
char		*ft_getenv(const char *var);
void		ft_setenv(const char *var, const char *value);
char		*var_name(const char *var);
bool		is_valid_var_name(const char *var);
void		pset_err(const char *prg, const char *v1, const char *v2, int err);
void		unexpected_token(const char *token);
void		process_cmd(t_node *cmds);
char		*get_cmd_path(const char *cmd);
void		ft_cmd(t_node *node);
void		ft_cmd_subshell(t_node *node);
bool		op_control(t_node *cmds);
bool		exec_redirections(t_list *redirs, int *pipe_fd);
bool		exec_heredocs(t_list *redirs, int stdin_fd);

void		fd_reset(void);
void		init_pipes(t_node *cmds);
void		close_pipes(t_node *cmds);
bool		all_same_cmd(t_node *first);

void		minishell_init(char *const *envp);
void		minishell_loop(void);
void		minishell_destroy(void);
char		*get_prompt(void);

void		nodeclear(t_node **node);
void		nodeadd_back(t_node **lst, t_node *new);
t_node		*nodelast(t_node *lst);
t_node		*nodenew(void);

t_node		*parse(t_list *tokens);
bool		is_valid_syntax(t_list *tokens);
char		*interpolate(char *str);
void		interpolate_arr(char **arr);
void		interpolate_redirs(t_list *redirs);

void		newline(int signal);
void		nothing(int signal);
void		stop_heredoc(int signal);
void		process_exit_status(int wstatus);

t_type		get_type(t_string token);
bool		is_redirection(t_type type);

t_list		*tokenize(t_tokenizer *tok);
char		cursor_char(const t_tokenizer *tok);
void		inc_cursor(t_tokenizer *tok);
void		eval_quote(t_tokenizer *tok);
void		eval_dquote(t_tokenizer *tok);
bool		end_of_token(const t_tokenizer *tok);
void		init_tokenizer(t_tokenizer *tok);

#endif
