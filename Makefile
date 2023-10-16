NAME		= minishell

SRC			= src
INC			= inc
OBJ			= obj
LIB			= lib
CC			= clang
CFLAGS		= -Wall -Wextra -Werror -Wpedantic -Wconversion
RM			= rm -rf

FTDIR		= libft
LIBFT		= ft
MAKELIBFT	= $(MAKE) --no-print-directory -C $(FTDIR)

HFILES		= minishell.h
BUILTIN_C	= cd.c builtin_main.c chemin_pwd.c echo.c environment_bis.c exit.c ft_export.c ft_unset.c

PARSING_C	= inter_main.c inter2.c parsing_main.c syntaxe.c token_main.c tokenizer_main.c tokenizer2.c

EXEC_C		= cmd_main.c cmd2.c execution.c heredoc.c pipe_main.c pipe2.c redirection.c

CFILES		= env_main.c errors.c main.c minishell.c node.c prompt_main.c signals_main.c

BUILTIN_DIR	= $(SRC)/builtin
PARSING_DIR	= $(SRC)/parsing
EXEC_DIR		= $(SRC)/execution

BUILTIN_SRC = $(addprefix $(BUILTIN_DIR)/, $(BUILTIN_C))
PARSING_SRC	=	$(addprefix $(PARSING_DIR)/, $(PARSING_C))
EXEC_SRC	=	$(addprefix $(EXEC_DIR)/, $(EXEC_C))

OFILES		=	$(CFILES:.c=.o) $(BUILTIN_C:.c=.o) $(PARSING_C:.c=.o) $(EXEC_C:.c=.o)

HEADERS		=	$(addprefix $(INC)/, $(HFILES))
OBJS		=	$(addprefix $(OBJ)/, $(OFILES))
SRCS		=	$(addprefix $(SRC)/, $(CFILES)) $(BUILTIN_SRC) $(PARSING_SRC) $(EXEC_SRC)

VPATH		=	$(SRC) $(BUILTIN_DIR) $(PARSING_DIR) $(EXEC_DIR)

$(OBJ)/%.o:	%.c
			$(CC) $(CFLAGS) -I. -I$(INC) -c $< -o $@

all:		CFLAGS += -O2 -DNDEBUG
all:		$(NAME)

$(NAME):	$(OBJ) $(OBJS)
			$(CC) $(OBJS) -L$(FTDIR) -l$(LIBFT) -L$(LIB) -lreadline -lcurses -o $(NAME)

$(OBJ):
			@mkdir -p $(OBJ)

nicke:		CFLAGS += -O2 -DNDEBUG
nicke:		$(OBJ) $(OBJS)
			$(CC) $(OBJS) -L$(FTDIR) -l$(LIBFT) -lreadline -o $(NAME)

debug:		CFLAGS += -g
debug:		$(NAME)

clean:
			@$(RM) $(OBJS) clean
			

fclean:		clean
			@$(RM) $(NAME) fclean
			

re:			fclean all

norme:
			@$(MAKELIBFT) norme
			@norminette $(SRCS) $(HEADERS)

.PHONY:		all clean fclean re norme linux debug