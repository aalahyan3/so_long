# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aalahyan <aalahyan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/04 17:22:32 by aalahyan          #+#    #+#              #
#    Updated: 2025/01/26 16:16:14 by aalahyan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC=cc
CFLAGS=-Wall -Wextra -Werror
MANDATORY_DIR=mandatory
BONUS_DIR=bonus
HEADERFILE=$(MANDATORY_DIR)/so_long.h
HEADERFILE_BONUS=$(BONUS_DIR)/so_long_bonus.h
HEADERFILE_LIBFT=$(LIBFT_DIR)/libft.h

LIBFT_DIR=libft
EXEC_FLAGS= -L$(LIBFT_DIR) -lft -lmlx -framework OpenGL -framework AppKit
LIBFT=$(LIBFT_DIR)/libft.a
BIN_DIR=bin
CFILES=	$(MANDATORY_DIR)/main.c \
		$(MANDATORY_DIR)/clear_memory.c \
		$(MANDATORY_DIR)/file_validation.c \
		$(MANDATORY_DIR)/map_parsing.c \
		$(MANDATORY_DIR)/map_parsing_ii.c \
		$(MANDATORY_DIR)/map_parsing_iii.c \
		$(MANDATORY_DIR)/render_frame.c \
		$(MANDATORY_DIR)/start_game.c \
		$(MANDATORY_DIR)/load_data.c


CFILES_BONUS=	$(BONUS_DIR)/main_bonus.c \
				$(BONUS_DIR)/file_validation_bonus.c \
				$(BONUS_DIR)/map_parsing_bonus.c \
				$(BONUS_DIR)/map_parsing_ii_bonus.c \
				$(BONUS_DIR)/map_parsing_iii_bonus.c \
				$(BONUS_DIR)/load_data_bonus.c \
				$(BONUS_DIR)/start_game_bonus.c \
				$(BONUS_DIR)/render_frame_bonus.c \
				$(BONUS_DIR)/render_frame_2_bonus.c \
				$(BONUS_DIR)/move_enemies_bonus.c \
				$(BONUS_DIR)/clear_memory_bonus.c 
OFILES=$(CFILES:$(MANDATORY_DIR)/%.c=$(BIN_DIR)/%.o)
BONUS_OFILES=$(CFILES_BONUS:$(BONUS_DIR)/%.c=$(BIN_DIR)/%.o)
NAME=so_long
NAME_BONUS=so_long_bonus

all: libft $(NAME)


$(NAME): $(BIN_DIR) $(OFILES)
	$(CC) $(OFILES) $(EXEC_FLAGS) -o $@
	
$(BIN_DIR)/%.o:$(MANDATORY_DIR)/%.c $(HEADERFILE)
	$(CC) $(CFLAGS) -c $< -o $@

libft: 
	@make -C $(LIBFT_DIR)

bonus:	libft $(NAME_BONUS)
$(NAME_BONUS): $(BIN_DIR) $(BONUS_OFILES)
	$(CC) $(BONUS_OFILES) $(EXEC_FLAGS) -o $(NAME_BONUS)

$(BIN_DIR)/%.o:$(BONUS_DIR)/%.c $(HEADERFILE_BONUS)
	$(CC) $(CFLAGS) -c $< -o $@	

$(BIN_DIR):
	mkdir -p $@
clean:
	make clean -C $(LIBFT_DIR)
	rm -rf $(BIN_DIR)
fclean: clean
	make fclean -C $(LIBFT_DIR)
	rm -rf $(NAME) $(NAME_BONUS)
re: fclean all
.PHONY:all clean fclean re bonus libft
