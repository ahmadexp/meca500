CC		:= gcc
CFLAGS		:= -Wall -g

CFLAGS += -lsocket

OBJDIR		:= obj
_OBJ		:= main.o ConnectToRobot.o
OBJ		:= $(patsubst %,$(OBJDIR)/%,$(_OBJ))
DEPS		:= ConnectToRobot.h

$(OBJDIR)/%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ) $(LIBS)
	$(CC) -o main $(OBJ) $(CFLAGS)

$(OBJ): | $(OBJDIR)

$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	rm $(OBJDIR)/*.o
	rm main
