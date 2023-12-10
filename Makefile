# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ccrecent <ccrecent@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/10 19:22:32 by ccrecent          #+#    #+#              #
#    Updated: 2023/12/02 13:06:47 by ccrecent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SOURCES = so_long.c \
		src/101_utils.c \
		src/103_check.c \
		src/105_check_2.c \
		src/107_flood_fill.c \
		src/109_initialize_matrix.c \
		src/201_graphics.c \
		src/202_load_clean.c	\
		src/203_draw.c \
		src/205_hook.c \
		src/301_up_move.c \
		src/303_right_move.c \
		src/305_down_move.c \
		src/307_left_move.c \
 				
OBJECTS = $(SOURCES:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g #-fsanitize=address
LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

MLX = MLX42/libmlx42.a -I include -lglfw -L "/Users/ccrecent/.brew/opt/glfw/lib/"

NAME = so_long

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(LIBFT) $(MLX)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@
	
$(LIBFT):
	@${MAKE} -C ${LIBFT_PATH}

clean:
	@${MAKE} -C ${LIBFT_PATH} clean
	@rm -rf ${OBJECTS}

fclean: clean
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re