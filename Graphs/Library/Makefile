default:all

all: BFS DFS tags

INTERNAL = graph

$(INTERNAL):
	gcc -g -c -I ./include src/$@.c -o obj/$@.o

library: $(INTERNAL)
	ar -rcs lib/libgraph.a obj/$(INTERNAL).o

DFS: library
	gcc -g -I ./include/ build/dfs.c -o bin/dfs -L ./lib/ -lgraph

BFS: library
	gcc -g -I ./include/ build/bfs.c -o bin/bfs -L ./lib/ -lgraph

tags:
	ctags -R --extras=+f *

clean:
	rm -f logs/* obj/* bin/* lib/* 
