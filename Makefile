addressbook:	addressbook.o entity.o main.o
		g++ -o addressbook addressbook.o entity.o main.o
main.o:	main.cpp
		g++ -c main.cpp
addressbook.o:	addressbook.cpp
		g++ -c addressbook.cpp
entity.o:	entity.cpp
		g++ -c entity.cpp
clean:
		rm *.o addressbook
