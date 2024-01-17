# **************************************************************************** #
#                                                                              #
#                                                         :::    ::::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lbouet   <@nix.os>                        +#+  +:+       #+#         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/31 16:34:08 by kroussar          #+#    #+#              #
#    Updated: 2024/01/12 00:49:47 by mmoussou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = libft.a

INCLUDE = include

# find -type f -name "*.c" | sed "s/\.\///g" | xargs -Iname echo "`printf '\t\t\t'`" name "\\"
SRCS = 		 src/io/get_next_line.c \
			 src/io/ft_putnbr_fd.c \
			 src/io/ft_putuhex_fd.c \
			 src/io/ft_putendl_fd.c \
			 src/io/ft_putstr_fd.c \
			 src/io/ft_printf.c \
			 src/io/ft_putchar_fd.c \
			 src/mem/ft_memchr.c \
			 src/mem/ft_calloc.c \
			 src/mem/ft_memcpy.c \
			 src/mem/ft_memset.c \
			 src/mem/ft_memcmp.c \
			 src/mem/ft_memmove.c \
			 src/mem/ft_bzero.c \
			 src/str/XtoX/ft_atol.c \
			 src/str/XtoX/ft_itoa.c \
			 src/str/XtoX/ft_atoi.c \
			 src/str/XtoX/ft_ltoa.c \
			 src/str/ft_strchr.c \
			 src/str/ft_strtrim.c \
			 src/str/ft_strcmp.c \
			 src/str/ft_striteri.c \
			 src/str/ft_strmapi.c \
			 src/str/ft_substr.c \
			 src/str/ft_strdup.c \
			 src/str/ft_strnstr.c \
			 src/str/ft_tolower.c \
			 src/str/ft_strlcpy.c \
			 src/str/ft_strlen.c \
			 src/str/ft_strjoin.c \
			 src/str/ft_strncmp.c \
			 src/str/ft_strrchr.c \
			 src/str/ft_split.c \
			 src/str/ft_strlcat.c \
			 src/str/ft_toupper.c \
			 src/char/ft_isdigit.c \
			 src/char/ft_isalnum.c \
			 src/char/ft_isprint.c \
			 src/char/ft_isalpha.c \
			 src/char/ft_isascii.c \
			 src/linked_lists/ft_lstmap.c \
			 src/linked_lists/ft_lstnew.c \
			 src/linked_lists/ft_lstclear.c \
			 src/linked_lists/ft_lstsize.c \
			 src/linked_lists/ft_lstadd_front.c \
			 src/linked_lists/ft_lstadd_back.c \
			 src/linked_lists/ft_lstiter.c \
			 src/linked_lists/ft_lstlast.c \
			 src/linked_lists/ft_lstdelone.c \

OBJS = $(SRCS:.c=.o)

COUNT	:=

define LIBFT_BANNER
\033[0;34m


		  _____     _____  ______   ________  _________  
		 |_   _|   |_   _||_   _ \ |_   __  ||  _   _  | 
		   | |       | |    | |_) |  | |_ \_||_/ | | \_| 
		   | |   _   | |    |  __'.  |  _|       | |     
		  _| |__/ | _| |_  _| |__) |_| |_       _| |_    
		 |________||_____||_______/|_____|     |_____|   
                                                 


\033[0m
endef

export LIBFT_BANNER


all: banner $(NAME)

banner:
	@printf "$$LIBFT_BANNER"

$(NAME): $(OBJS)
	@echo -n -e "\n\n󱉟 Making library.\r"
	@ar rcs $(NAME) $(OBJS)
	@sleep 0.2
	@echo -n -e "󱉟 Making library..\r"
	@sleep 0.2
	@echo -n -e "󱉟 Making library...\r"
	@sleep 0.2
	@echo "󱉟 Library done !    "

%.o: %.c
	$(eval COUNT += x)
	@echo -n -e "\r󱌣 Compiling... : | "
	@for i in $(SRCS); do \
		echo -n -e ""; \
	done
	@echo -n -e " | $<               \r"
	@echo -n -e "󱌣 Compiling... : | "
	@for j in $(COUNT); do \
		echo -n ""; \
	done
	@$(CC) $(CFLAGS) -I ./$(INCLUDE) $< -c -o $@

clean:
	@for i in $(OBJS) $(BONUSOBJS); do \
		if test -f "$$i"; then \
			rm -f $$i; \
			sleep 0.02; \
			echo -n -e " Cleaned "; \
			echo -n -e "$$i                        \r"; \
		fi; \
	done
	@echo " Cleaned all objects !                     "
	@sleep 0.1

fclean: clean
	@if test -f "$(NAME)"; then \
		echo " Cleaned $(NAME)"; \
		sleep 0.1; \
		rm -f $(NAME); \
	fi


re: fclean all

.PHONY: all fclean clean re banner
