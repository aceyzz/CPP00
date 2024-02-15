# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cedmulle <cedmulle@student.42lausanne.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/14 14:16:28 by cedmulle          #+#    #+#              #
#    Updated: 2024/02/14 17:45:17 by cedmulle         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= account

SRC_DIR	= src/
SRC		= $(SRC_DIR)Account.cpp \
			$(SRC_DIR)tests.cpp

INC_DIR	= inc/
INC		= $(INC_DIR)Account.hpp

OBJ		= $(SRC:.cpp=.o)
CXX		= c++
CFL		= -Wall -Werror -Wextra -std=c++98 -I./$(INC_DIR)

all:		$(NAME)

$(NAME):	$(OBJ)
	$(CXX) $(CFL) -o $(NAME) $(OBJ)

%o:			%.cpp
	$(CXX) $(CFL) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean:		clean
	rm -rf $(NAME)

re:			fclean all
