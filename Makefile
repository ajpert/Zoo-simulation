CC = g++ -std=c++11
exe_file = a
$(exe_file): animal.o sea_lion.o tiger.o bear.o zoo.o prog.o
	$(CC) animal.o sea_lion.o tiger.o bear.o zoo.o prog.o -o $(exe_file)
animal.o: animal.cpp
	$(CC) -c animal.cpp
sea_lion.o: sea_lion.cpp
	$(CC) -c sea_lion.cpp
tiger.o: tiger.cpp
	$(CC) -c tiger.cpp
bear.o: bear.cpp
	$(CC) -c bear.cpp
zoo.o: zoo.cpp
	$(CC) -c zoo.cpp
prog.o: prog.cpp
	$(CC) -c prog.cpp

clean:
	rm -f *.out *.o $(exe_file)