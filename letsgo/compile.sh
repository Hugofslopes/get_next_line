#!/bin/bash

comp = cc -Wall -Wextra -Werror -D BUFFER_SIZE=4 get_next_line.c simple_main.c get_next_line_utils.c -o main -g
$(COMP)
