FLAGS=-O3 -lm
EXEC=rtm
CC=gcc
all: $(EXEC)

$(EXEC): $(EXEC).c
	$(CC) $(FLAGS) $(EXEC).c -c -o $(EXEC).o
	$(CC) $(FLAGS) $(EXEC).o -o $(EXEC)

clean:
	rm -f *.o $(EXEC)
