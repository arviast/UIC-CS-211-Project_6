1: ajamsr2Proj6.o Island.o
	g++ -o 1 ajamsr2Proj6.o Island.o

ajamsr2Proj6.o: ajamsr2Proj6.cpp Island.h
	g++ -c ajamsr2Proj6.cpp
    
Island.o: Island.cpp Island.h
	g++ -c Island.cpp
