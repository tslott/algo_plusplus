CC = g++
CFLAGS = -c -Wall
EXECUTABLE = run_me.out
OBJECTS = main.o linked_list.o lru_cache.o

build: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

$%.o: $%.cpp $%.h
	$(CC) $(CFLAGS) $^ $@

clean:
	rm -f *.o $(EXECUTABLE)
