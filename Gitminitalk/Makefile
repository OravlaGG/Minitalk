# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alvargom <alvargom@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/09 12:01:03 by alvargom          #+#    #+#              #
#    Updated: 2024/07/23 11:49:57 by alvargom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program

SERVER = server
SERVER_B = server_bonus

CLIENT = client
CLIENT_B = client_bonus

CC = clang

LIB = ./minitalk_utils.c

CFLAGS = -Wall -Werror -Wextra

all: $(SERVER) $(CLIENT)
$(NAME): all

$(SERVER):
	$(CC) $(CFLAGS) server.c $(LIB) -o $(SERVER)

$(CLIENT):
	$(CC) $(CFLAGS) client.c $(LIB) -o $(CLIENT)

clean:
	rm -rf $(SERVER) $(CLIENT) 
	rm -rf $(SERVER_B) $(CLIENT_B) 

fclean: clean

re: fclean all

bonus: $(SERVER_B) $(CLIENT_B)
$(NAME): all

$(SERVER_B):
	$(CC) $(CFLAGS) server_bonus.c $(LIB) -o $(SERVER_B)

$(CLIENT_B):
	$(CC) $(CFLAGS) client_bonus.c $(LIB) -o $(CLIENT_B)


.PHONY: all flean clean re