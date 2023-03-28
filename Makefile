# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vmustone <vmustone@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/24 16:39:22 by emajuri           #+#    #+#              #
#    Updated: 2023/03/28 14:34:09 by vmustone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAMES = server

NAMEC = client

LIBFT = libft.a

SRCS = server.c

SRCC = client.c

OSRCS = $(SRCS:%.c=%.o)

OSRCC = $(SRCC:%.c=%.o)

WWW = -Wall -Wextra -Werror

all: $(LIBFT) $(NAMES) $(NAMEC)

$(LIBFT):
	make -C libft

$(NAMES): $(OSRCS)
	cc $(WWW) $(OSRCS) -L libft -lft -o $(NAMES)

$(NAMEC): $(OSRCC)
	cc $(WWW) $(OSRCC) -L libft -lft -o $(NAMEC)
clean:
	rm -f $(OSRCS) $(OSRCC)
	make clean -C libft

fclean: clean
	rm -f $(NAMES) $(NAMEC)
	rm -f libft/$(LIBFT)

re: fclean all

.PHONY: all clean fclean re
