CFLAGS = -O2 -std=c++11
CC = g++

all: main

main: main.cpp md5.o rainbowTable.o
	$(CC) $(CFLAGS) main.cpp md5.o rainbowTable.o -o main

md5.o: md5.cpp md5.h
	$(CC) $(CFLAGS) md5.cpp md5.h -c

rainbowTable.o: rainbowTable.cpp rainbowTable.h
	$(CC) $(CFLAGS) rainbowTable.cpp rainbowTable.h -c

clean:
	rm main
	rm *.o
	rm *.h.gch
