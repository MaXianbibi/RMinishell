NAME = minishell
LIBFT = libft/libft.a
CC = @gcc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -Llib/readline -lreadline -lcurses 
RM = @rm -f
INCLUDE = -I include/ -I lib/

SRC_DIR = src/
SRC_FILES =	minishell.c lexer.c other.c parser.c error.c find_cmd.c echo.c execute.c

OBJ_DIR = objs/
OBJS = ${addprefix ${OBJ_DIR}, $(SRC_FILES:.c=.o)}

${OBJ_DIR}%.o: ${SRC_DIR}%.c
	@echo "$(_BLUE)$(_BOLD)Compilation Printf: $< $(_END)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

#Couleurs!
_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_RED=$'\x1b[31m
_GREEN=$'\x1b[32m
_YELLOW=$'\x1b[33m
_BLUE=$'\x1b[34m
_PURPLE=$'\x1b[35m
_WHITE=$'\x1b[37m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m
_IBLUE=$'\x1b[44m
_IPURPLE=$'\x1b[45m
_IWHITE=$'\x1b[47m

all: $(NAME)

$(NAME): ${OBJ_DIR} $(OBJS) ${LIBFT}
	${CC} ${OBJS} ${LIBFT} $(LFLAGS) -o $@

${OBJ_DIR}:
	mkdir -p $@

${LIBFT}:
	@make -C ./libft

clean:
	@$(MAKE) clean -C ./libft
	@$(RM) -r ${OBJ_DIR}

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(RM) $(NAME)

re: fclean all
