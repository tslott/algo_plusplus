CC = g++
CFLAGS = -c -std=c++17 -Wall
EXECUTABLE = run_me.out
OBJECTS = main.o inverted_index.o

build: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXECUTABLE)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

inverted_index.o: inverted_index.cpp inverted_index.h
	$(CC) $(CFLAGS) inverted_index.cpp

$%.o: $%.cpp $%.h
	$(CC) $(CFLAGS) $< $@

clean:
	rm -f *.o $(EXECUTABLE)
