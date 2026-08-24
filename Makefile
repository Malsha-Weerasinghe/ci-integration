CC      := gcc
CFLAGS  := -Wall -Wextra -std=c99 -Iinclude
SRC     := $(wildcard src/*.c)
OBJ     := $(SRC:.c=.o)

all: build/liborders.a

build/liborders.a: $(OBJ)
	@mkdir -p build
	ar rcs $@ $(OBJ)

clean:
	rm -f $(OBJ)
	rm -rf build

.PHONY: all clean
