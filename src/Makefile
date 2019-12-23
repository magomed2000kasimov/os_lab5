lab5dyn2: mainDy.c
	gcc mainDy.c -ldl -o lab5dyn2


lab5dyn1: mainSt.c list.c
	gcc -fPIC -c list.c
	gcc -shared list.o -o libmylist.so
	gcc -c mainSt.c
	gcc mainSt.o -L. -lmylist -o lab5dyn1

