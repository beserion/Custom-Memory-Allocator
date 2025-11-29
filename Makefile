# Makefile
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -pthread
INCLUDES = -I./include
SRC = src/allocator.c
TEST = tests/test_mm.c
NAME = mini_malloc_test

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) $(INCLUDES) $(SRC) $(TEST) -o $(NAME)

clean:
	rm -f $(NAME)

re: clean all
