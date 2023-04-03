CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=main.cpp src/board.cpp src/gameplay.cpp
INCLUDES=-Iheaders
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=minesweeper

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $(INCLUDES) $< -o $@

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE)
