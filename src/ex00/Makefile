# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: faaraujo <faaraujo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/22 18:48:56 by faaraujo          #+#    #+#              #
#    Updated: 2024/06/05 21:24:33 by faaraujo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#******************************************************************************#
#                                 VARIABLES                                    #
#******************************************************************************#

NAME = zombie
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRC = Zombie.cpp newZombie.cpp randomChump.cpp main.cpp
OBJS = $(SRC:.cpp=.o)

# .c.o:
# 	$(CXX) -c $(CXXFLAGS) $< -o $@

#******************************************************************************#
#                                 SCRIPT                                       #
#******************************************************************************#

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(PURPLE)====================================$(CLR_RESET)"
	@echo "$(GREEN)Compiling of $(RED)$(NAME)...$(CLR_RESET)"
	
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	
	@echo "$(RED)$(NAME) $(GREEN)is ready!$(CLR_RESET)"
	@echo "$(PURPLE)====================================$(CLR_RESET)"
clean:
	rm -f $(OBJS)
	
	clear
	@echo "$(RED)$(NAME) object $(GREEN)files have been deleted.$(CLR_RESET)"
	
fclean: clean
	rm -f $(NAME)
	
	clear
	@echo "$(RED)$(NAME) $(GREEN)has been deleted.$(CLR_RESET)"

re: fclean all
	@echo "$(RED)$(NAME) $(GREEN)has been recompiled.$(CLR_RESET)"
	@echo "$(PURPLE)====================================$(CLR_RESET)"

.PHONY: all clean fclean re

#******************************************************************************#
#                                 COLORS                                       #
#******************************************************************************#

CLR_RESET	= \033[0m
RED		    = \033[1;31m
GREEN		= \033[1;32m
YELLOW		= \033[1;33m
BLUE		= \033[1;34m
CYAN 		= \033[1;36m
PURPLE 		= \033[0;35m