CC = g++
CFLAGS = -c -Wall

project: esame

esame: main.o sportello.o baccount.o client.o filedb.o trans.o
	$(CC) main.o sportello.o baccount.o client.o filedb.o trans.o -o esame

main.o: ../main.cpp
	$(CC) $(CFLAGS) ../main.cpp

sportello.o: ../sportello.cpp
	$(CC) $(CFLAGS) ../sportello.cpp

baccount.o: ../baccount.cpp
	$(CC) $(CFLAGS) ../baccount.cpp

client.o: ../client.cpp
	$(CC) $(CFLAGS) ../client.cpp

filedb.o: ../filedb.cpp
	$(CC) $(CFLAGS) ../filedb.cpp

trans.o: ../trans.cpp
	$(CC) $(CFLAGS) ../trans.cpp

clean:
	rm *.o esame