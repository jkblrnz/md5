CFLAGS = -O2 -std=c++11
CC = g++

a.out: main.cpp md5.cpp rainbowTable.cpp
	$(CC) $(CFLAGS) main.cpp md5.cpp rainbowTable.cpp

clean:
	rm a.out
