# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <mmoussou@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/22 07:21:18 by mmoussou          #+#    #+#              #
#    Updated: 2024/01/24 20:40:19 by mmoussou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SHELL = bash

CC = gcc

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

LIBFT_INCLUDE = $(LIBFT_DIR)/include

CFLAGS = -Wall -Wextra -Werror -lX11

INCLUDE = ./

NAME = ywm

SRCS = ywm.c


all: $(NAME)

$(LIBFT_DIR):
	@git clone https://github.com/y-syo/libft $(LIBFT_DIR)
	@printf " \x1B[1;34m[  ]\x1B[0m Cloned libft.\n"

$(LIBFT): $(LIBFT_DIR)
	@make -s -C $(LIBFT_DIR)

$(NAME): $(LIBFT)
	@printf "\x1B[2K\r \x1B[1;32m[ 󱌣 ]\x1B[0m Objects Compiled."
	@printf "\n \x1B[1;33m[ 󱉟 ]\x1B[0m Compiling $(NAME)..."
	$(CC) $(SRCS) $(LIBFT) -I$(INCLUDE) -I$(LIBFT_INCLUDE) -o $(NAME) $(CFLAGS)
	@printf "\x1B[2K\r \x1B[1;33m[ 󱉟 ]\x1B[0m $(NAME) Compiled.\n"

clean:
	@make -s -C $(LIBFT_DIR) clean
	@rm -f $(OBJS)
	@printf " \x1B[1;31m[  ]\x1B[0m Deleted Objects.\n"

fclean:
	@make -s -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@printf " \x1B[1;31m[  ]\x1B[0m Deleted binary.\n"

re: fclean all

.PHONY: all server client clean fclean re
