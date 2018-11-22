CC=g++
CFLAGS=-I std=c++1z
hellomake: hellomake.c
	$(CC) -o hellomake hellomake.c

