# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 13:45:05 by vstockma          #+#    #+#              #
#    Updated: 2023/05/04 16:26:51 by vstockma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c split_input.c

LIBFT = ./libft/libft.a
	
OBJS = $(SRCS:.c=.o)
CFLAGS = -g -Wall -Werror -Wextra 
CC = cc 
RM = rm -f
NAME = minishell

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re: clean all