CC=g++

gal: src/main.cpp src/cliente.hpp src/empresa.hpp
	$(CC) -o bin/gal.exe src/main.cpp src/cliente.hpp src/empresa.hpp