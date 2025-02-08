# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 09:56:03 by shebaz            #+#    #+#              #
#    Updated: 2025/02/08 23:16:28 by shebaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc #-fsanitize=address -g3

CFLAGS = -Wall -Wextra -Werror

SRCS =	main.c \
		$(wildcard get_next_line/*.c) \
		$(wildcard libft/*.c) \
		$(wildcard parsing/*.c) \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all