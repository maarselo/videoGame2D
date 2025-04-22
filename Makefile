NAME = so_long

HEADER = so_long.h
SRCS = error.c entry.c utilsEntry.c create.c free.c main.c \
			format.c
OBJS = $(SRCS:.c=.o)

LIBFT_DIR=./Libft
LIBFT=$(LIBFT_DIR)/libft.a

CC = cc -g
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

GREEN = \033[1;32m
BLUE = \033[1;34m
YELLOW = \033[1;33m
RED = \033[1;31m
RESET = \033[0m

all: $(NAME)

$(LIBFT): 
	@echo "$(BLUE)->Compilando Libft...$(RESET)"
	@make -C $(LIBFT_DIR)
	@make -C $(LIBFT_DIR) bonus

$(NAME): $(OBJS) $(LIBFT) $(HEADER) Makefile
	@echo "$(GREEN)✔ Compilando $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)	 Compilación completada!$(RESET)"

clean :
	@echo "$(RED)  Limpiando objetos...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJS)

fclean: clean
	@echo "$(RED)  Borrando ejecutable...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re