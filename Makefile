# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: shebaz <shebaz@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 09:56:03 by shebaz            #+#    #+#              #
#    Updated: 2025/02/17 21:47:00 by shebaz           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc #-fsanitize=address -g3

CFLAGS = -Wall -Wextra -Werror #-lmlx -lX11 -lXext -lm
X_FLAGS = -lmlx -lX11 -lXext -lm 

SRCS =	main.c mouvement.c \
		$(wildcard get_next_line/*.c) \
		$(wildcard Libft/*.c) \
		$(wildcard parsing/*.c) \

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(X_FLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all