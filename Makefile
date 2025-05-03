# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvillavi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/03 03:16:45 by mvillavi          #+#    #+#              #
#    Updated: 2025/05/03 03:16:47 by mvillavi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR = src
INCLUDE_DIR = include
OBJ_DIR = obj
LIBFT_DIR=./Libs/Libft
MLX_DIR=./Libs/MLX42

HEADER = $(INCLUDE_DIR)/so_long.h
SRCS = $(SRC_DIR)/error.c $(SRC_DIR)/entry.c $(SRC_DIR)/utilsEntry.c \
		$(SRC_DIR)/create_map.c $(SRC_DIR)/free.c $(SRC_DIR)/main.c \
		$(SRC_DIR)/format.c $(SRC_DIR)/utilsFormat.c $(SRC_DIR)/createGame.c \
		$(SRC_DIR)/utilsCreateGame.c $(SRC_DIR)/errorFree.c

OBJS = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

LIBFT=$(LIBFT_DIR)/libft.a
MLX=$(MLX_DIR)/build/libmlx42.a
MLX_HEADER=$(MLX_DIR)/include
MLX_FLAGS=-ldl -lglfw -pthread -lm

CC = cc -g
CFLAGS = -Wall -Werror -Wextra -I$(INCLUDE_DIR)
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
	@$(CC) $(CFLAGS) $(OBJS) $(MLX) $(INCLUDES_MLX) $(MLX_FLAGS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)	 Compilación completada!$(RESET)"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@echo "$(YELLOW)Compilando $<...$(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@echo "$(RED)  Limpiando objetos...$(RESET)"
	@make -C $(LIBFT_DIR) clean
	@$(RM) $(OBJ_DIR)

fclean: clean
	@echo "$(RED)  Borrando ejecutable...$(RESET)"
	@make -C $(LIBFT_DIR) fclean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
