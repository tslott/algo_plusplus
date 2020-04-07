CC = g++
CFLAGS = -c -Wall
TARGET = run_me
OBJECTS = main.o linked_list.o #lru_cache.o

build: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

linked_list.o: linked_list.cpp linked_list.hpp
	$(CC) $(CFLAGS) linked_list.cpp

# lru_cache.o: lru_cache.cpp lru_cache.hpp
# 	$(CC) $(CFLAGS) lru_cache.cpp

clean:
	rm -f *.o $(TARGET)
