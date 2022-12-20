# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adiouane <adiouane@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/15 18:17:03 by adiouane          #+#    #+#              #
#    Updated: 2022/12/16 02:40:12 by adiouane         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fixed

SRC =  main.cpp Fixed.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++ -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)
clean:
	rm -rf $(OBJ)

fclean: 
	rm -rf $(OBJ) $(NAME)
re: fclean all
		