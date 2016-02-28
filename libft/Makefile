# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldubos <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 16:26:37 by ldubos            #+#    #+#              #
#    Updated: 2016/01/20 11:01:21 by ldubos           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Wextra -Werror
NAME=libft.a
DIRSRCS=srcs/
SRCS=$(DIRSRCS)ft_strlen.c \
	 $(DIRSRCS)ft_strcpy.c \
	 $(DIRSRCS)ft_strncpy.c \
	 $(DIRSRCS)ft_strdup.c \
	 $(DIRSRCS)ft_strcat.c \
	 $(DIRSRCS)ft_strncat.c \
	 $(DIRSRCS)ft_strlcat.c \
	 $(DIRSRCS)ft_strchr.c \
	 $(DIRSRCS)ft_strrchr.c \
	 $(DIRSRCS)ft_strstr.c \
	 $(DIRSRCS)ft_strnstr.c \
	 $(DIRSRCS)ft_strcmp.c \
	 $(DIRSRCS)ft_strncmp.c \
	 $(DIRSRCS)ft_isalpha.c \
	 $(DIRSRCS)ft_isdigit.c \
	 $(DIRSRCS)ft_isalnum.c \
	 $(DIRSRCS)ft_isascii.c \
	 $(DIRSRCS)ft_isprint.c \
	 $(DIRSRCS)ft_toupper.c \
	 $(DIRSRCS)ft_tolower.c \
	 $(DIRSRCS)ft_atoi.c \
	 $(DIRSRCS)ft_memset.c \
	 $(DIRSRCS)ft_bzero.c \
	 $(DIRSRCS)ft_memcpy.c \
	 $(DIRSRCS)ft_memccpy.c \
	 $(DIRSRCS)ft_memmove.c \
	 $(DIRSRCS)ft_memchr.c \
	 $(DIRSRCS)ft_memcmp.c \
	 $(DIRSRCS)ft_memalloc.c \
	 $(DIRSRCS)ft_memdel.c \
	 $(DIRSRCS)ft_strnew.c \
	 $(DIRSRCS)ft_strdel.c \
	 $(DIRSRCS)ft_strclr.c \
	 $(DIRSRCS)ft_striter.c \
	 $(DIRSRCS)ft_striteri.c \
	 $(DIRSRCS)ft_strmap.c \
	 $(DIRSRCS)ft_strmapi.c \
	 $(DIRSRCS)ft_strnequ.c \
	 $(DIRSRCS)ft_strequ.c \
	 $(DIRSRCS)ft_strsub.c \
	 $(DIRSRCS)ft_strjoin.c \
	 $(DIRSRCS)ft_strtrim.c \
	 $(DIRSRCS)ft_strsplit.c \
	 $(DIRSRCS)ft_itoa.c \
	 $(DIRSRCS)ft_putchar.c \
	 $(DIRSRCS)ft_putstr.c \
	 $(DIRSRCS)ft_putendl.c \
	 $(DIRSRCS)ft_putnbr.c \
	 $(DIRSRCS)ft_putchar_fd.c \
	 $(DIRSRCS)ft_putstr_fd.c \
	 $(DIRSRCS)ft_putendl_fd.c \
	 $(DIRSRCS)ft_putnbr_fd.c \
	 $(DIRSRCS)ft_lstnew.c \
	 $(DIRSRCS)ft_lstdelone.c \
	 $(DIRSRCS)ft_lstdel.c \
	 $(DIRSRCS)ft_lstadd.c \
	 $(DIRSRCS)ft_lstiter.c \
	 $(DIRSRCS)ft_lstmap.c 
OBJS=$(SRCS:.c=.o)
	INC_DIR=-I./includes/
	INC=libft.h

all		: $(NAME)

$(NAME)	: $(OBJS)
	@printf "\033[1;33m[Libft all]\t\t\033[1;32m.\033[0;02m";
	@ar -rc $(NAME) $(OBJS)
	@printf "\033[1;32m.\033[0;02m";
	@ranlib $(NAME)
	@printf "\033[1;32m.\t\t[OK]\033[0;02m\n";

%.o		: %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC_DIR)

.PHONY	: clean fclean re

clean	:
	@rm -f $(OBJS)
	@printf "\033[1;33m[Libft clean]\t\t\033[1;32m.\t\t[OK]\033[0;02m\n";

fclean	:
	@rm -f $(NAME)
	@printf "\033[1;33m[Libft fclean]\t\t\033[1;32m.\t\t[OK]\033[0;02m\n";

re		: fclean all
