movieTheaterDB: movieTheaterDB.o movieTheaterDB_movie.o movieTheaterDB_actor.o relationship.o
	gcc -o movieTheaterDB movieTheaterDB.o movieTheaterDB_movie.o movieTheaterDB_actor.o relationship.o

movieTheaterDB.o: movieTheaterDB.c movieTheaterDB_movie.h movieTheaterDB_actor.h relationship.h
	gcc -c movieTheaterDB.c

movieTheaterDB_movie.o: movieTheaterDB_movie.c movieTheaterDB_movie.h
	gcc -c movieTheaterDB_movie.c

movieTheaterDB_actor.o: movieTheaterDB_actor.c movieTheaterDB_actor.h
	gcc -c movieTheaterDB_actor.c

relationship.o: relationship.c relationship.h
	gcc -c relationship.c

clean:
	rm -f movieTheaterDB movieTheaterDB_actor.o movieTheaterDB_movie.o movieTheaterDB.o relationship.o
