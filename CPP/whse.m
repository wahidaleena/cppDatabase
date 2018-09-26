CC=g++
CFLAGS=-c -I/usr/include/SDL2 -std=c++11 -Wall
LDFLAGS=
FLAGS=-lSDL2 -lSDL2_image
SRC_PATH=data
VPATH=${SRC_PATH}
SOURCES=whse_rcpt.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=whse_rcpt
BINDIR=/usr/bin


all: $(SOURCES) $(EXECUTABLE)
        
$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@ $(FLAGS)
	rm *.o

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ $(FLAGS)

clean:
	rm *.o $(EXECUTABLE)

install:
	#install -s $(EXECUTABLE) $(BINDIR)
	sudo cp -u $(EXECUTABLE) $(BINDIR)
uninstall:
	sudo rm $(BINDIR)/$(EXECUTABLE)

