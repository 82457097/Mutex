
all:
	g++ -std=c++11 test1.cpp -o test1 -pthread

clean:
	rm test1
