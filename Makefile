CC=g++
CFLAGS=-g --std=c++11 -Wall

lab3.exe: main.cpp coinchange.cpp
	$(CC) -o lab2.exe $(CFLAGS) main.cpp coinchange.cpp 

