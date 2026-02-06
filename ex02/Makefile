# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkaras-g <bkaras-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/16 14:08:56 by bkaras-g          #+#    #+#              #
#    Updated: 2026/02/06 15:01:39 by bkaras-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.SILENT:

NAME = geta_wonderful_fix

SRC = Fixed.cpp \
		main.cpp

HEADERS = Fixed.hpp

RM = rm -f
OBJ := $(patsubst %.cpp, %.o, $(SRC))
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -ggdb

all: $(NAME)

$(NAME): $(OBJ) $(HEADER) Makefile
	@$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	@echo  "Mandatory part compilation ok"

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -I. -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@echo  "Clean done"

fclean: clean
	@$(RM) $(NAME)

re: fclean all

dev: all clean

.PHONY: all clean fclean re dev
