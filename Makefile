# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/29 17:55:04 by gmorais-          #+#    #+#              #
#    Updated: 2023/09/01 12:18:23 by gmorais-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

SRCS_NAME =	main.c utils.c ./ft_printf/ft_printf.c\
			./ft_printf/ft_numbers.c\
			./ft_printf/ft_words.c\

CC = cc
CFLAGS = -Wall -Werror -Wextra -g

RM = rm -rf

LIBFT = ./libft/libft.a
LIBFT_PATH = ./libft

OBJS = $(SRCS_NAME:.c=.o)

all: $(NAME)

$(NAME) : $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

#usado para ver se ja tem algo compilado no libft
$(LIBFT):  $(shell make -C $(LIBFT_PATH) -q)
	make  -s -C $(LIBFT_PATH)
		
clean:
		make clean -s -C $(LIBFT_PATH)
		rm -rf $(OBJS)

fclean: clean
		make fclean -s -C $(LIBFT_PATH)
		rm -f $(NAME)

re: fclean all
