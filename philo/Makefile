# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nminotte <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 16:47:18 by nminotte          #+#    #+#              #
#    Updated: 2023/05/22 14:41:45 by nminotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=  philo

SRC = ./mandatory/parsing.c \
	./mandatory/clear.c \
	./mandatory/ft_atoi.c \
	./mandatory/philo.c \
	./mandatory/thread.c \
	./mandatory/ft_msg.c \
	./mandatory/time.c \
	./mandatory/init.c \
	./mandatory/main.c \
	./mandatory/eat.c 
	
OBJS = $(SRC:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g -pthread

CC = clang

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

all : $(LIBFT) $(NAME)

$(LIBFT):
	make

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	
clean :
	@rm -rf $(OBJS)
	
fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean re fclean
