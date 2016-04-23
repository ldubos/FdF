# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/20 10:21:26 by ldubos            #+#    #+#              #
#    Updated: 2016/04/23 08:24:06 by ldubos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export CFLAGS=#-Wall -Wextra -Werror
NAME=fdf
MLX=-lmlx -framework OpenGL -framework AppKit
SRCS_DIR=srcs/
SRCS=$(SRCS_DIR)main.c \
	 $(SRCS_DIR)get_next_line.c \
	 $(SRCS_DIR)error.c \
	 $(SRCS_DIR)obj.c \
	 $(SRCS_DIR)hook.c \
	 $(SRCS_DIR)draw.c
OBJS=$(SRCS:.c=.o)
	INC_DIR=-I./includes/ -I./libft/includes/
	LIB_DIR=-L./libft -lft -L./minilibx $(MLX)
	LIB_MAKE=libft/

all		: $(NAME)

$(NAME) : $(OBJS)
	@cd $(LIB_MAKE) && $(MAKE)
	@printf "\033[1;33m[FdF all]\t\t\033[1;32m.\033[0;02m";
	@gcc $(CFLAGS) $(OBJS) -o $(NAME) $(LIB_DIR) $(LFLAGS)
	@printf "\033[1;32m.\t\t[OK]\033[0;02m\n";

%.o		: %.c
	@gcc $(CFLAGS) $(INC_DIR) -c $< -o $@

.PHONY	: clean fclean re

clean	:
	@cd $(LIB_MAKE) && $(MAKE) $@
	@printf "\033[1;33m[FdF clean]\t\t\033[1;32m.\033[0;02m";
	@rm -f $(OBJS)
	@printf "\033[1;32m.\t\t[OK]\033[0;02m\n";

fclean	:
	@cd $(LIB_MAKE) && $(MAKE) $@
	@printf "\033[1;33m[FdF fclean]\t\t\033[1;32m.\033[0;02m";
	@rm -f $(NAME)
	@printf "\033[1;32m.\t\t[OK]\033[0;02m\n";

re		: fclean all
