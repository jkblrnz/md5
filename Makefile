CFLAGS = -O2 -std=c++11
CC = g++

all: main.out

main.out: main.cpp md5.o rainbowTable.o
	$(CC) $(CFLAGS) main.cpp -o main.out

md5.o: md5.cpp md5.h
	$(CC) $(CFLAGS) md5.cpp md5.h -c

rainbowTable.o: rainbowTable.cpp rainbowTable.h
	$(CC) $(CFLAGS) rainbowTable.cpp rainbowTable.h -c

clean:
	rm main.out
	rm *.o
	rm *.h.gch
