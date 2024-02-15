# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 10:27:26 by cedmulle          #+#    #+#              #
#    Updated: 2024/02/11 10:37:08 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= megaphone
SRC		= megaphone.cpp
OBJ		= $(SRC:.cpp=.o)
CXX		= c++
CFL		= -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFL) -o $(NAME) $(OBJ)

%.o: %.cpp
	$(CXX) $(CFL) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
