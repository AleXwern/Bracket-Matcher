# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: AleXwern <AleXwern@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/25 17:02:22 by AleXwern          #+#    #+#              #
#    Updated: 2024/11/25 21:19:04 by AleXwern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= brackets.exe
FLAG	= -m64 -Wall -Wextra -Werror
SRCFILE	= reversepolish.cpp
OBJ		= $(addprefix ./obj/,$(SRCFILE:.cpp=.o))
INCLS	= -I ./includes
GREEN	= \033[0;32m
PURPLE	= \033[0;35m
STOP	= \033[0m
TEMP0	= 0

.PHONY: all clean fclean re

all: $(NAME)

./obj/%.o:./src/%.cpp
	@echo "Compiling $(GREEN)$@$(STOP)"
	@mkdir -p obj
	g++ $(FLAG) -c $< -o $@ $(INCLS)
	@cp $@ ../obj

folders:
	@mkdir -p build
	@mkdir -p obj

$(NAME): folders $(OBJ)
	g++ -o $(NAME) $(OBJ)

clean:
	@/bin/rm -f $(OBJ)
	@/bin/rm -rf ./obj

fclean: clean
	@rm -rf $(NAME)

re: fclean all
