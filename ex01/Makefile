# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xvi <xvi@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 13:21:08 by cedmulle          #+#    #+#              #
#    Updated: 2024/02/13 10:02:39 by xvi              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= phonebook

SRC_DIR	= src/
SRC		= $(SRC_DIR)main.cpp \
			$(SRC_DIR)Contact.cpp \
			$(SRC_DIR)PhoneBook.cpp

INC_DIR	= inc/
INC		= $(INC_DIR)tools.hpp \
			$(INC_DIR)Contact.hpp \
			$(INC_DIR)PhoneBook.hpp

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
