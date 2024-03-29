# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcasale <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/13 17:32:54 by tcasale           #+#    #+#              #
#    Updated: 2023/01/06 12:52:09 by tcasale          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRCS	= $(wildcard srcs/*.c)

OBJS	=${SRCS:.c=.o}

HEADER	= includes

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
FDFLAGS	= srcs/mlx/libmlx.a -framework OpenGL -framework AppKit
RM		= rm -f

%.o: %.c
			$(CC) $(CFLAGS) -I./srcs/libftprintf/libftprintf.a -I./srcs/get_next_line/get_next_line.a -I./srcs/mlx/libmlx.a -c  $< -o $@

all:	$(NAME)

$(NAME):	$(OBJS) libft get_next_line mlx
			$(CC) $(OBJS) $(FDFLAGS) ./srcs/libftprintf/libftprintf.a ./srcs/get_next_line/get_next_line.a -o $(NAME)

bonus:	$(NAME)

libft:
	$(MAKE) -C ./srcs/libftprintf

mlx:
	$(MAKE) -C ./srcs/mlx

get_next_line:
	$(MAKE) -C ./srcs/get_next_line

clean:
		$(MAKE) -C ./srcs/libftprintf $@
		$(MAKE) -C ./srcs/get_next_line $@
		$(MAKE) -C ./srcs/mlx $@
		$(RM) $(OBJS)

fclean:	clean
		$(MAKE) -C ./srcs/libftprintf $@
		$(MAKE) -C ./srcs/get_next_line $@
		$(MAKE) -C ./srcs/mlx $@
		$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
