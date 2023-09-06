all: fifo sjf rr

fifo: fifo.cpp ReadDataFile.cpp
	g++ -o fifo fifo.cpp ReadDataFile.cpp -Wall -Werror -std=c++20 -g

sjf: sjf.cpp ReadDataFile.cpp
	g++ -o sjf sjf.cpp ReadDataFile.cpp -Wall -Werror -std=c++20 -g

rr: rr.cpp ReadDataFile.cpp
	g++ -o rr rr.cpp ReadDataFile.cpp -Wall -Werror -std=c++20 -g