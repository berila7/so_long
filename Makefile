# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberila <mberila@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 11:55:01 by mberila           #+#    #+#              #
#    Updated: 2025/01/18 16:13:19 by mberila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = so_long
LIBFT_DIR = ./lib/libft
GNL_DIR = ./lib/get_next_line

LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS    = $(wildcard ./src/*.c $(GNL_DIR)/*.c $(LIBFT_DIR)/*.c)
OBJ_DIR = obj
# Remove the leading ./ from the object paths
OBJ     = $(patsubst ./%.c, $(OBJ_DIR)/%.o, $(SRCS))

CC      = cc
MLX     = -lmlx -framework OpenGL -framework AppKit
RM      = rm -rf
CFLAGS  = -Wall -Wextra -Werror -I$(LIBFT_DIR)

# Rules
all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(LIBFT_LIB) $(OBJ_DIR)/lib/libft/*.o
	$(CC) $(OBJ) $(MLX) $(LIBFT_LIB) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re
