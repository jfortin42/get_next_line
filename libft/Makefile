# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfortin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/24 10:29:00 by jfortin           #+#    #+#              #
#    Updated: 2015/12/12 17:25:28 by jfortin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

SRC = ft_strndup.c \
		ft_strchr.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strncpy.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
				@ar rc $(NAME) $(OBJ)
				@echo "$(NAME) created"
				@ranlib $(NAME)
				@echo "$(NAME) indexed"

%.o: %.c
				@gcc $(FLAG) -I ./includes/ -c $< -o $@

clean:
		@rm -f $(OBJ)
		@echo "OBJ deleted"

fclean: clean
		@rm -f $(NAME)
		@echo "$(NAME) deleted"

re : fclean all

.PHONY: all, clean, fclean, re
