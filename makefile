OBJS	= DynamicArray.o
SOURCE	= DynamicArray.c
HEADER	= DynamicArray.h
OUT	= darraytest
CC	 = gcc
FLAGS	 = -g -c -Wall
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

DynamicArray.o: DynamicArray.c
	$(CC) $(FLAGS) DynamicArray.c 


clean:
	rm -f $(OBJS) $(OUT)