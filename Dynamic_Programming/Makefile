
SOURCES = $(wildcard *.c)
EXECS = $(SOURCES:.c=)

CC = gcc

CC_FLAGS = -g

default: all

all:$(EXECS)

%: %.c
	$(CC) $(CC_FLAGS) $< -o $@

clean:
	rm $(EXECS)
