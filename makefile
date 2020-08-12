CC = g++ -std=c++11
all: ‫‪Goodreads.out‬‬

‫‪Goodreads.out‬‬: main.o functions.o GoodReads.o User.o Author.o Book.o Review.o Date.o
	${CC} -o Goodreads.out main.o functions.o GoodReads.o User.o Author.o Book.o Review.o Date.o
main.o: main.cpp functions.hpp
	${CC} -c main.cpp
functions.o: functions.cpp functions.hpp GoodReads.hpp
	${CC} -c functions.cpp
GoodReads.o: GoodReads.cpp GoodReads.hpp User.hpp
	${CC} -c GoodReads.cpp
User.o: User.cpp User.hpp Author.hpp
	${CC} -c User.cpp
Author.o: Author.cpp Author.hpp Book.hpp
	${CC} -c Author.cpp
Book.o: Book.cpp Book.hpp Review.hpp
	${CC} -c Book.cpp
Review.o: Review.cpp Review.hpp Date.hpp
	${CC} -c Review.cpp
Date.o: Date.cpp Date.hpp
	${CC} -c Date.cpp
clean:
	rm *.o
	rm ‫‪Goodreads.out