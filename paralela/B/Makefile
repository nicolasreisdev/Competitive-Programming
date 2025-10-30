CC = gcc
FLAGS = -O3
LDFLAGS =

RM=rm -f

EXEC=nQueens

all: $(EXEC)

$(EXEC):
	$(CC) $(FLAGS) $(EXEC).c -c -o $(EXEC).o
	$(CC) $(FLAGS) $(EXEC).o -o $(EXEC) $(LDFLAGS)

clean:
	$(RM) $(EXEC).o $(EXEC)
