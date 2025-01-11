# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 17:22:32 by aalahyan          #+#    #+#              #
#    Updated: 2025/01/06 19:32:30 by aalahyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Wextra -Werror
HEADERFILE=so_long.h
LIBFT_DIR=libft
EXEC_FLAGS= -L$(LIBFT_DIR) -lft -lmlx -framework OpenGL -framework AppKit
LIBFT=$(LIBFT_DIR)/libft.a
BIN_DIR=bin
CFILES=	main.c \
		map_parsing.c \
		free_memory.c \
		map_validation.c \
		path_validation.c \
		render_game.c \
		render_frame.c

OFILES=$(CFILES:%.c=$(BIN_DIR)/%.o)                 

NAME=so_long

all:$(NAME)

$(NAME): $(LIBFT) $(BIN_DIR) $(OFILES)
	$(CC) $(OFILES) $(EXEC_FLAGS) -o $@
	
$(BIN_DIR)/%.o:%.c $(HEADERFILE)
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

$(BIN_DIR):
	mkdir $@

clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(OFILES)
fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME)
re: fclean all
