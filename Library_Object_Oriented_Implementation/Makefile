
all: Goodreads.out

Goodreads.out: main.o functions.o goodreads.o review_info.o user_info.o book_info.o author_info.o follower_info.o date.o
	g++ -std=c++11 -o Goodreads.out main.o review_info.o functions.o goodreads.o user_info.o book_info.o author_info.o follower_info.o date.o


main.o: main.cpp functions.h goodreads.h review_info.h user_info.h book_info.h author_info.h follower_info.h
	g++ -std=c++11 -c main.cpp


goodreads.o: goodreads.cpp goodreads.h functions.h review_info.h user_info.h book_info.h author_info.h follower_info.h date.h
	g++ -std=c++11 -c goodreads.cpp


functions.o: functions.cpp functions.h user_info.h book_info.h author_info.h review_info.h follower_info.h
	g++ -std=c++11 -c functions.cpp

review_info.o: review_info.cpp review_info.h date.h
	g++ -std=c++11 -c review_info.cpp

user_info.o: user_info.cpp user_info.h book_info.h date.h
	g++ -std=c++11 -c user_info.cpp

book_info.o: book_info.cpp book_info.h
	g++ -std=c++11 -c book_info.cpp

author_info.o: author_info.cpp author_info.h date.h
	g++ -std=c++11 -c author_info.cpp

follower_info.o: follower_info.cpp functions.h
	g++ -std=c++11 -c follower_info.cpp


date.o: date.cpp date.h
	g++ -std=c++11 -c date.cpp

clean:
	rm *.o
	rm Goodreads.out