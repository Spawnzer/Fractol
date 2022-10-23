# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adubeau <marvin@42quebec.com>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/05 15:03:25 by adubeau           #+#    #+#              #
#    Updated: 2022/05/01 15:26:58 by adubeau          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= 	fractol

SRCS		= 	srcs/main.c \
				srcs/color.c \
				srcs/sets.c \
				srcs/draw.c \
				srcs/events.c \
				srcs/utils.c

OBJS		= $(SRCS:.c=.o)
RM			= rm -rf
EXEC		= gcc -o
FLAGS		= -Wall -Werror -Wextra -c -g
INCS		= ./includes
CC			= gcc
CP			= cp
MLX 		= -lmlx -framework OpenGL -framework AppKit

.c.o:
	$(CC) $(FLAGS) $< -o $(<:.c=.o) -I$(INCS)

all: $(NAME)

$(NAME): $(OBJS)
	@$(EXEC) $(NAME) $(OBJS) $(MLX)

clean:
	@clear all
	@$(RM) $(OBJS)

fclean: clean
	@$(RM) $(NAME)
	@$(RM)

re: fclean all clean
