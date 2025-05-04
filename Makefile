# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/11 09:48:21 by hfilipe-          #+#    #+#              #
#    Updated: 2025/05/04 10:12:33 by hfilipe-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -ggdb
BUFFER_SIZE = 1000
SRC_FILES = get_next_line.c get_next_line_utils.c
BONUS_FILES = get_next_line_bonus.c get_next_line_utils_bonus.c
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes
MAIN_SRC = test_files/main.c
MAIN_SRC2 = test_files/main_bonus.c
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
BONUS_SRC = $(addprefix $(SRC_DIR)/, $(BONUS_FILES))
OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
BONUS_OBJ = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(BONUS_SRC))
MAIN_OBJ = $(OBJ_DIR)/main.o
MAIN_OBJ2 = $(OBJ_DIR)/main_bonus.o
INCLUDE = -I$(INC_DIR)
EXEC = main
EXECB = mainbonus
RM = rm -f
DEPS = $(OBJ:.o=.d) $(BONUS_OBJ:.o=.d)

all: $(OBJ_DIR) $(EXEC)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(EXEC): $(OBJ) $(MAIN_OBJ)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $^ -o $@ -g

bonus: $(EXECB)

$(EXECB): $(BONUS_OBJ) $(MAIN_OBJ2)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) $^ -o $@ -g

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

$(OBJ_DIR)/main.o: test_files/main.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

$(OBJ_DIR)/main_bonus.o: test_files/main_bonus.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -D BUFFER_SIZE=$(BUFFER_SIZE) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ) $(MAIN_OBJ) $(MAIN_OBJ2) 
	rmdir $(OBJ_DIR)
	
fclean: clean
	$(RM) $(EXEC) $(EXECB)

re: fclean all

-include $(DEPS)
