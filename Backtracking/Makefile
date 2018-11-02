
SOURCES = $(wildcard *.c)
EXECS = $(SOURCES:.c=)

CC = gcc

CC_FLAGS = -g

default: all

all:$(EXECS)

%: %.c
	$(CC) $(CC_FLAGS) $< -o $@

gray_code:
	gcc -g gray_code.c -o gray_code -lm

clean:
	rm $(EXECS)
