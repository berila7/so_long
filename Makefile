# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberila <mberila@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 11:55:01 by mberila           #+#    #+#              #
#    Updated: 2025/01/23 16:39:36 by mberila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

LIBFT_DIR = ./lib/libft
GNL_DIR = ./lib/get_next_line
FPF_DIR = ./lib/ft_printf

LIBFT_LIB = $(LIBFT_DIR)/libft.a
FPF_LIB = $(FPF_DIR)/libftprintf.a

SRCS_MAN = $(wildcard ./mandatory/src/*.c $(GNL_DIR)/*.c $(LIBFT_DIR)/*.c)
OBJS_MAN = $(SRCS_MAN:.c=.o)

SRCS_BON = $(wildcard ./bonus/src/*.c $(GNL_DIR)/*.c $(LIBFT_DIR)/*.c)
OBJS_BON = $(SRCS_BON:.c=.o)
# Remove the leading ./ from the object paths

CC      = cc
MLX     = -lmlx -framework OpenGL -framework AppKit
RM      = rm -rf
CFLAGS  = -Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(FPF_DIR)

# Rules
all: $(NAME)
bonus: $(NAME_BONUS)

$(NAME): $(LIBFT_LIB) $(FPF_LIB) $(OBJS_MAN)
	$(CC) $(CFLAGS) $^ $(MLX) $(LIBFT_LIB) $(FPF_LIB) -o $(NAME)
	
$(NAME_BONUS): $(LIBFT_LIB)  $(FPF_LIB) $(OBJS_BON)
	$(CC) $(CFLAGS) $^ $(MLX) $(LIBFT_LIB) $(FPF_LIB) -o $(NAME_BONUS)

mandatory/%.o: mandatory/%.c includes/so_long.h
	$(CC) $(CFLAGS) -Imlx -Ilib -c $< -o $@
	
bonus/%.o: bonus/%_bonus.c includes/so_long_bonus.h
	$(CC) $(CFLAGS) -Imlx -Ilib -c $< -o $@

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)
	
$(FPF_LIB):
	$(MAKE) -C $(FPF_DIR)

clean:
	$(RM) $(OBJS_MAN) $(OBJS_BON)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FPF_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FPF_DIR) fclean

re: fclean all

.PHONY : $(LIBFT_DIR) $(FPF_DIR)