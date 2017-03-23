CC		:= gcc
CFLAGS		:= -Wall -g

CFLAGS += -lsocket

OBJ		:= main.o 

main: $(OBJ)
	$(CC) -o main $(OBJ) $(CFLAGS)

clean:
	rm *.o
	rm main
