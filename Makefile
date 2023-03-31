# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:39:22 by emajuri           #+#    #+#              #
#    Updated: 2023/03/31 21:49:33 by vmustone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minitalk

SERVER = server

CLIENT = client

LIBFT = libft/libft.a

SRC_SERVER = server.c

SRC_CLIENT = client.c

WWW = -Wall -Wextra -Werror

all: $(LIBFT) $(SERVER) $(CLIENT)

$(NAME): all

$(LIBFT):
	make -C libft

$(SERVER): $(SRC_SERVER) $(LIBFT)
	cc $(WWW) $(SRC_SERVER) $(LIBFT) -o $(SERVER)

$(CLIENT): $(SRC_CLIENT) $(LIBFT)
	cc $(WWW) $(SRC_CLIENT) $(LIBFT) -o $(CLIENT)
	
clean:
	make clean -C libft

fclean: clean
	rm -f $(SERVER) $(CLIENT)
	rm -f $(LIBFT)

re: fclean all

.PHONY: $(NAME) all clean fclean re