# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mberila <mberila@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/08 11:55:01 by mberila           #+#    #+#              #
#    Updated: 2025/01/26 09:53:26 by mberila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
NAME_BONUS 	=	so_long_bonus

CC			=	cc
MLX			=	-lmlx -framework OpenGL -framework AppKit
RM			=	rm -rf
CFLAGS		=	-Wall -Wextra -Werror -I$(LIBFT_DIR) -I$(FPF_DIR)

LIBFT_DIR	=	lib/libft
GNL_DIR		=	lib/get_next_line
FPF_DIR		= 	lib/ft_printf

LIBFT_LIB	=	$(LIBFT_DIR)/libft.a
FPF_LIB		=	$(FPF_DIR)/libftprintf.a

GNL_SRCS	=	$(GNL_DIR)/get_next_line.c \
				$(GNL_DIR)/get_next_line_utils.c

SRCS		=	$(GNL_SRCS) \
				mandatory/src/errors.c \
				mandatory/src/free_game.c \
				mandatory/src/init_game.c \
				mandatory/src/main.c \
				mandatory/src/map_utils.c \
				mandatory/src/map_validation.c \
				mandatory/src/moves.c \
				mandatory/src/path_validations.c \
				mandatory/src/render.c \
				mandatory/src/textures.c \

SRCS_BONUS	=	$(GNL_SRCS) \
				bonus/src/animation_bonus.c \
				bonus/src/enemy_bonus.c \
				bonus/src/errors_bonus.c \
				bonus/src/free_game_bonus.c \
				bonus/src/init_game_bonus.c \
				bonus/src/main_bonus.c \
				bonus/src/map_utils_bonus.c \
				bonus/src/map_validation_bonus.c \
				bonus/src/moves_bonus.c \
				bonus/src/path_validations_bonus.c \
				bonus/src/render_bonus.c \
				bonus/src/textures_bonus.c \

OBJS		=	$(SRCS:.c=.o)
OBJS_BONUS	=	$(SRCS_BONUS:.c=.o)

# Rules
all			:	$(NAME)
bonus		:	$(NAME_BONUS)

$(NAME): $(LIBFT_LIB) $(FPF_LIB) $(OBJS)
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
	$(RM) $(OBJS) $(OBJS_BON)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FPF_DIR) clean

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FPF_DIR) fclean

re: fclean all

.PHONY : $(LIBFT_DIR) $(FPF_DIR)