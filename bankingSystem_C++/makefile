all: main

main: main.o Manager.o Customer.o Maintainer.o 
		g++ main.o Manager.o Customer.o Maintainer.o -o main

main.o: main.cpp Manager.hpp Customer.hpp Maintainer.hpp
		g++ -c main.cpp

Manager.o: Manager.cpp Manager.hpp Customer.hpp
		g++ -c Manager.cpp

Customer.o: Customer.cpp Customer.hpp
		g++ -c Customer.cpp

Maintainer.o: Maintainer.cpp Maintainer.hpp Manager.hpp Customer.hpp
		g++ -c Maintainer.cpp

clean:
		rm -rf *o main

