# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:39:22 by emajuri           #+#    #+#              #
#    Updated: 2023/03/30 21:33:53 by vmustone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = server

NAMEC = client

LIBFT = libft.a

SRCS = server.c

SRCC = client.c

WWW = -Wall -Wextra -Werror

all: $(LIBFT) $(NAMES) $(NAMEC)

$(LIBFT):
	make -C libft

$(NAMES): $(SRCS)
	cc $(WWW) $(SRCS) -L libft -lft -o $(NAMES)

$(NAMEC): $(SRCC)
	cc $(WWW) $(SRCC) -L libft -lft -o $(NAMEC)
	
clean:
	make clean -C libft

fclean: clean
	rm -f $(NAMES) $(NAMEC)
	rm -f libft/$(LIBFT)

re: fclean all

.PHONY: all clean fclean re
