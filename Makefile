# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:48:21 by hfilipe-          #+#    #+#              #
#    Updated: 2024/11/11 10:37:10 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar rcs
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
SRC_DIR = ./SRC
OBJ_DIR = ./OBJ
MAIN_DIR =./MAIN
SRC_FILES = $(addprefix $(SRC_DIR)/, get_next_line.c get_next_line_utils.c)
OBJ_FILES = $(SRC_FILES:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
BONUS_FILES = $(addprefix $(SRC_DIR)/, get_next_line_bonus.c get_next_line_utils_bonus.c)
LIB_NAME = get_next_line.a
LIB_NAME_BONUS = get_next_line_bonus.a
HEAD = ./INCLUDES
MAIN_SRC = $(MAIN_DIR)/main.c
MAIN_SRC2 = $(MAIN_DIR)/main_bonus.c
EXEC = main
EXECB = main2

all: $(LIB_NAME)
$(LIB_NAME): $(OBJ_FILES)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) -I$(HEAD) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ_DIR)/*.o

fclean: clean
	$(RM) $(LIB_NAME) $(EXEC) $(EXECB) $(LIB_NAME_BONUS)

re: fclean all 

bonus: $(LIB_NAME_BONUS) 
$(LIB_NAME_BONUS): $(BONUS_OBJ_FILES)
	$(AR) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c	
	$(CC) -I$(HEAD) $(CFLAGS) -c $< -o $@

main: $(EXEC)
	$(CC) -I$(HEAD) $(CFLAGS) $(SRC_FILES) $(MAIN_SRC) -o $(EXEC) -g

main2: $(EXECB)
	$(CC) -I$(HEAD) $(CFLAGS) $(BONUS_FILES) $(MAIN_SRC2) -o $(EXECB) -g
