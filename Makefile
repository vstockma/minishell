# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vstockma <vstockma@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/02 13:45:05 by vstockma          #+#    #+#              #
#    Updated: 2023/05/08 10:46:05 by vstockma         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = main.c pipes.c builtins.c redirections.c split_input.c split_utils.c get_len.c

LIBFT = ./libft/libft.a
	
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Werror -Wextra 
CC = cc 
RM = rm -f
NAME = minishell

all: $(NAME)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -lreadline $(LIBFT) -o $(NAME)

clean:
	$(RM) $(OBJS)
	$(MAKE) clean -C ./libft

fclean: clean
	$(RM) $(NAME)
	$(MAKE) fclean -C ./libft

re: clean all
