CC = gcc
FLAGS = -O3
LDFLAGS = -lm

RM=rm -f

EXEC=aco

all: $(EXEC)

$(EXEC):
	$(CC) $(FLAGS) $(EXEC).c -c -o $(EXEC).o
	$(CC) $(FLAGS) $(EXEC).o -o $(EXEC) $(LDFLAGS)

clean:
	$(RM) $(EXEC).o $(EXEC)
