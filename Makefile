OBJ=src/heap_sort.o src/main.o src/merge_sort.o src/search.o src/util.o

buscaOrdenacao: main.o util.o search.o heap_sort.o merge_sort.o
	gcc $(OBJ) -o buscaOrdenacao -Ofast -Wall -std=c17

main.o: src/main.c
	gcc src/main.c -c -I include/ -Wall -std=c17 -o src/main.o

util.o: src/util.c
	gcc src/util.c -c -I include/ -Wall -std=c17 -o src/util.o

search.o: src/search.c
	gcc src/search.c -c -I include/ -Wall -std=c17 -o src/search.o

heap_sort.o: src/heap_sort.c
	gcc src/heap_sort.c -c -I include/ -Wall -std=c17 -o src/heap_sort.o

merge_sort.o: src/merge_sort.c
	gcc src/merge_sort.c -c -I include/ -Wall -std=c17 -o src/merge_sort.o

.PHONY: clean

clean:
	-rm $(OBJ) buscaOrdenacao
