NAME = minishell
LIBFT = libft/libft.a
CC = @gcc
CFLAGS = -Wall -Wextra -Werror -g
LFLAGS = -Llib/readline -lreadline -lcurses 
RM = @rm -f
INCLUDE = -I include/ -I lib/

SRC_DIR = src/
SRC_FILES = $(wildcard $(SRC_DIR)*.c)

BUILTINS_DIR = src/builtins/
BUILTINS_FILES = $(wildcard $(BUILTINS_DIR)*.c)

ERROR_DIR = src/error/
ERROR_FILES = $(wildcard $(ERROR_DIR)*.c)

EXECUTE_DIR = src/execute/
EXECUTE_FILES = $(wildcard $(EXECUTE_DIR)*.c)

PARSING_DIR = src/parsing/
PARSING_FILES = $(wildcard $(PARSING_DIR)*.c)

OBJ_DIR = objs/
OBJS = $(addprefix $(OBJ_DIR), $(notdir $(SRC_FILES:.c=.o) $(notdir $(BUILTINS_FILES:.c=.o)) $(notdir $(ERROR_FILES:.c=.o)) $(notdir $(EXECUTE_FILES:.c=.o)) $(notdir $(PARSING_FILES:.c=.o))))


${OBJ_DIR}%.o: $(BUILTINS_DIR)%.c
	@echo "$(_YELLOW)$(_BOLD)Compilation BUILTINS: $< $(_END)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${OBJ_DIR}%.o: $(SRC_DIR)%.c 
	@echo "$(_GREEN)$(_BOLD)Compilation MAIN: $< $(_END)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${OBJ_DIR}%.o: $(ERROR_DIR)%.c 
	@echo "$(_RED)$(_BOLD)Compilation ERROR_FILES: $< $(_END)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${OBJ_DIR}%.o: $(EXECUTE_DIR)%.c 
	@echo "$(_PURPLE)$(_BOLD)Compilation EXECUTE_FILES: $< $(_END)"
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

${OBJ_DIR}%.o: $(PARSING_DIR)%.c 
	@echo "$(_BLUE)$(_BOLD)Compilation PARSING_FILES: $< $(_END)"
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

.PHONY: all clean fclean re