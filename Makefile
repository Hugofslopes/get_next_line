# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:48:21 by hfilipe-          #+#    #+#              #
#    Updated: 2025/01/09 12:44:04 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
BUFFER_SIZE = 1000
SRC_FILES = get_next_line.c get_next_line_utils.c
BONUS_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c
MAIN_SRC = tests_main/main.c
MAIN_SRC2 = tests_main/main_bonus.c
OBJ_FILES = $(SRC_FILES:.c=.o) $(MAIN_SRC:.c=.o)
BONUS_OBJ_FILES = $(BONUS_FILES:.c=.o) $(MAIN_SRC2:.c=.o)
EXEC = main
EXECB = mainbonus

all: $(EXEC)
$(EXEC): $(OBJ_FILES)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $^ -o $@ -g

bonus: $(EXECB)
$(EXECB): $(BONUS_OBJ_FILES)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $^ -o $@ -g

clean:
	$(RM) $(OBJ_FILES) $(BONUS_OBJ_FILES)
	
fclean: clean
	$(RM) $(EXEC) $(EXECB) 

re: fclean all 
