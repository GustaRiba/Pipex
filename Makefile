# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 17:55:04 by gmorais-          #+#    #+#              #
#    Updated: 2023/06/29 18:00:49 by gmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS_NAME =	teste.c\
			utils.c

CC = cc
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address

RM = rm -rf

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

OBJS = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT)  -o $(NAME)

$(LIBFT):  $(shell make -C $(LIBFT_PATH) -q)
	make  -s -C $(LIBFT_PATH)
	make bonus  -s -C $(LIBFT_PATH)
		
clean:
		make clean -s -C $(LIBFT_PATH)
		rm -rf $(OBJS)

fclean: clean
		make fclean -s -C $(LIBFT_PATH)
		rm -f $(NAME)

re: fclean all
