# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoussou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/17 12:07:18 by mmoussou          #+#    #+#              #
#    Updated: 2024/01/17 12:24:43 by mmoussou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

LIBFT_PATH = libft
LIBFT_SRC =  $(LIBFT_PATH)/src/io/get_next_line.c \
			 $(LIBFT_PATH)/src/io/ft_putnbr_fd.c \
			 $(LIBFT_PATH)/src/io/ft_putuhex_fd.c \
			 $(LIBFT_PATH)/src/io/ft_putendl_fd.c \
			 $(LIBFT_PATH)/src/io/ft_putstr_fd.c \
			 $(LIBFT_PATH)/src/io/ft_printf.c \
			 $(LIBFT_PATH)/src/io/ft_putchar_fd.c \
			 $(LIBFT_PATH)/src/mem/ft_memchr.c \
			 $(LIBFT_PATH)/src/mem/ft_calloc.c \
			 $(LIBFT_PATH)/src/mem/ft_memcpy.c \
			 $(LIBFT_PATH)/src/mem/ft_memset.c \
			 $(LIBFT_PATH)/src/mem/ft_memcmp.c \
			 $(LIBFT_PATH)/src/mem/ft_memmove.c \
			 $(LIBFT_PATH)/src/mem/ft_bzero.c \
			 $(LIBFT_PATH)/src/str/XtoX/ft_atol.c \
			 $(LIBFT_PATH)/src/str/XtoX/ft_itoa.c \
			 $(LIBFT_PATH)/src/str/XtoX/ft_atoi.c \
			 $(LIBFT_PATH)/src/str/XtoX/ft_ltoa.c \
			 $(LIBFT_PATH)/src/str/ft_strchr.c \
			 $(LIBFT_PATH)/src/str/ft_strtrim.c \
			 $(LIBFT_PATH)/src/str/ft_strcmp.c \
			 $(LIBFT_PATH)/src/str/ft_striteri.c \
			 $(LIBFT_PATH)/src/str/ft_strmapi.c \
			 $(LIBFT_PATH)/src/str/ft_substr.c \
			 $(LIBFT_PATH)/src/str/ft_strdup.c \
			 $(LIBFT_PATH)/src/str/ft_strnstr.c \
			 $(LIBFT_PATH)/src/str/ft_tolower.c \
			 $(LIBFT_PATH)/src/str/ft_strlcpy.c \
			 $(LIBFT_PATH)/src/str/ft_strlen.c \
			 $(LIBFT_PATH)/src/str/ft_strjoin.c \
			 $(LIBFT_PATH)/src/str/ft_strncmp.c \
			 $(LIBFT_PATH)/src/str/ft_strrchr.c \
			 $(LIBFT_PATH)/src/str/ft_split.c \
			 $(LIBFT_PATH)/src/str/ft_strlcat.c \
			 $(LIBFT_PATH)/src/str/ft_toupper.c \
			 $(LIBFT_PATH)/src/char/ft_isdigit.c \
			 $(LIBFT_PATH)/src/char/ft_isalnum.c \
			 $(LIBFT_PATH)/src/char/ft_isprint.c \
			 $(LIBFT_PATH)/src/char/ft_isalpha.c \
			 $(LIBFT_PATH)/src/char/ft_isascii.c \
			 $(LIBFT_PATH)/src/linked_lists/ft_lstmap.c \
			 $(LIBFT_PATH)/src/linked_lists/ft_lstnew.c \
			 $(LIBFT_PATH)/src/linked_lists/ft_lstclear.c \
			 $(LIBFT_PATH)/src/linked_lists/ft_lstsize.c \
			 $(LIBFT_PATH)/src/linked_lists/ft_lstadd_front.c \
			 $(LIBFT_PATH)/src/linked_lists/ft_lstadd_back.c \
			 $(LIBFT_PATH)/src/linked_lists/ft_lstiter.c \
			 $(LIBFT_PATH)/src/linked_lists/ft_lstlast.c \
			 $(LIBFT_PATH)/src/linked_lists/ft_lstdelone.c

LIBFT_OBJ = ${LIBFT_SRC:.c=.o}

CFLAGS = -O3 -ffast-math -Wall -Wextra

LIBS = -lXft -lX11 -lXcursor -lXft -lfontconfig -lXcomposite

FREETYPEINC = /usr/include/freetype2

INCS = -I${FREETYPEINC} -I./$(LIBFT_PATH)/include

SRC = ywm.c

OBJ = ${SRC:.c=.o}

all: ywm

.c.o:
	$(CC) -c $(CFLAGS) $(LIBS) $(INCS) $< -o $@

ywm: $(OBJ) $(LIBFT_OBJ)
	$(CC) -o $@ $(OBJ) $(LIBFT_OBJ) $(LIBS) $(INCS)

clean:
	rm -f $(OBJ) $(LIBFT_OBJ)

fclean: clean
	rm -f ywm

re: fclean ywm

.PHONY: all fclean clean re
