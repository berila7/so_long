# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberila <mberila@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 11:55:01 by mberila           #+#    #+#              #
#    Updated: 2025/01/20 17:31:44 by mberila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT_DIR = ./lib/libft
GNL_DIR = ./lib/get_next_line

LIBFT_LIB = $(LIBFT_DIR)/libft.a

SRCS_MAN = $(wildcard ./mandatory/src/*.c $(GNL_DIR)/*.c $(LIBFT_DIR)/*.c)
OBJS_MAN = $(SRCS_MAN:.c=.o)

SRCS_BON = $(wildcard ./bonus/src/*.c $(GNL_DIR)/*.c $(LIBFT_DIR)/*.c)
OBJS_BON = $(SRCS_BON:.c=.o)
# Remove the leading ./ from the object paths

CC      = cc
MLX     = -lmlx -framework OpenGL -framework AppKit
RM      = rm -rf
CFLAGS  = -Wall -Wextra -Werror -I$(LIBFT_DIR)

# Rules
all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(LIBFT_LIB) $(OBJS_MAN)
	$(CC) $(CFLAGS) $^ $(MLX) $(LIBFT_LIB) -o $(NAME)
	
$(NAME_BONUS): $(LIBFT_LIB) $(OBJS_BON)
	$(CC) $(CFLAGS) $^ $(MLX) $(LIBFT_LIB) -o $(NAME_BONUS)

mandatory/%.o: mandatory/%.c mandatory/so_long.h
	$(CC) $(CFLAGS) -Imlx -Ilib -c $< -o $@
	
bonus/%.o: bonus/%_bonus.c includes/so_long_bonus.h
	$(CC) $(CFLAGS) -Imlx -Ilib -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS_MAN) $(OBJS_BON)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

