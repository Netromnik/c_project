CC=gcc
CFLAG=-c -Wall -Werror -Wextra
QGRAPH= ../build/graph
GRAPHIC=../src/graphic.c

all:
		$(CC) $(CFLAG) $(GRAPHIC)   -o $(QGRAPH)

clean:
		rm -rf $(QGRAPH)

rebuild:
		clean all