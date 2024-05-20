/*
skullar5 - 251292956
This program implements and designs a database with the movies along with the movie codes, title, genre and rating in this theater.
It manages a movie database with operations to insert, search for, update, and print movie information as well as quit the program
*/
// include libraries for standard io, string manipulation and character type functions
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//constant TOTAL_MOVIE_NAMES represents maximum number of movie names in theater is 100  
//constant TOTAL_MOVIE_GENRES represents maximum number of movie genres in theater is 25
#define TOTAL_MOVIE_NAMES 100
#define TOTAL_MOVIE_GENRES 25

// structure representing a movie with movie code, name, genre, and rating (out of 10)
struct movie {
    int code;
    char movieName[TOTAL_MOVIE_NAMES];
    char movieGenre[TOTAL_MOVIE_GENRES];
    float movieRating;
};

// declaration and initialization of global variable numOfMovies representing number of movies in database
int numOfMovies = 0;

// find_movie function finds index of movie in array
int find_movie(struct movie movies[], int code) {
    // iterate through array of movies in database 
    //then if operation code from movie in array with specified operation code
    for (int i = 0; i < numOfMovies; i++) {
        if (movies[i].code == code) {
            // then return the index 
            return i;
        }
    }
    // otherwise if movie is not found then return -1
    return -1;
}

// readString function reads string with specified length n
int readString(char str[], int n) {
    // declaration and initialization of variable character and i representing characters in string an index
    int character, i = 0;

    // read characters until non-whitespace character is found
    while (isspace(character = getchar()));

    // read characters until new line or end of file then
    while (character != '\n' && character != EOF) {
        // if index is with specified max length n then store character in string str
        // and increment index by 1 each time
        if (i < n) {
            str[i++] = character;
        }
        // get next character 
        character = getchar();
    }
    //and if reached new line or end of file then set character as \0 (null) 
    str[i] = '\0';
    // return index i
    return i;
}

// insertMovie function inserts a movie into database
void insertMovie(struct movie movies[]) {
    // declaration of code variable representing movie code
    int code;
    // declaration of name array and genre array with length of TOTAL_MOVIE_NAMES and TOTAL_MOVIE_GENRES
    char name[TOTAL_MOVIE_NAMES];
    char genre[TOTAL_MOVIE_GENRES];
    //declaration of rating variable representing movie rating
    float rating;

    // prompt user for movie code 
    printf("        Enter movie code: ");
    scanf("%d", &code); // and then read movie code from user and store in coding variable

    // if the number of movies in theater match maximum number of movies theater can have then
    if (numOfMovies == TOTAL_MOVIE_NAMES) {
        // print to screen that database is full 
        printf("Database is full, cannot add any more movies.\n");
        // then return from function
        return;
    }

    // if the operation code is less than 0 then print to screen that it is invalid movie code
    // then return from function
    if (code < 0) {
        printf("Please try again, invalid movie operation code.\n");
        return;
    }

    // if movie with specified code already exists in database (returns index greater or equal to 0) 
    if (find_movie(movies, code) >= 0) {
        // then print to screen that movie already exists
        printf("Movie already exists.\n");
        // then  from function
        return;
    }

    // set operation code of latest movie in array to specified code
    movies[numOfMovies].code = code;

    // prompt user for movie name and call readString function to read movie name from user
    printf("        Enter movie name: ");
    readString(movies[numOfMovies].movieName, TOTAL_MOVIE_NAMES);

    // prompt user for movie genre and call readString function to read movie genre from user
    printf("        Enter movie genre: ");
    readString(movies[numOfMovies].movieGenre, TOTAL_MOVIE_GENRES);

    // prompt user for movie rating and then read movie rating from user and store in rating variable
    printf("        Enter movie rating: ");
    scanf("%f", &rating);

    // if rating isnt between 0.0 to 10.0 then print to screen that it is invalid movie rating
    // then return from function
    if (rating < 0.0 || rating > 10.0) {
        printf("Please try again, invalid movie rating.\n");
        return;
    }

    // set movie rating of latest movie in array to specified rating then increment number of movies in array by 1
    movies[numOfMovies].movieRating = rating;
    numOfMovies++;
}

// printMovie function prints list of movie and its information
void printMovie(struct movie movies[]) {
    // print header with column title indicating column of code, title, genre and rating with formatting for alignment and spacing
    // movie code left aligned in 12 character wide column, movie name left aligned in 38 character wide column, 
    // movie genre left aligned in 27 character wide column, movie rating displayed with one decimal place
    printf("%-12s%-37s%-27s%-s\n", "Movie Code", "Movie Name", "Movie Genre", "Movie Rating");

    // iterate through array of movies 
    for (int i = 0; i < numOfMovies; i++) {
        // initialize array which represents copy of movie name that will be striped to limit to 35 characters (including null character)
        char stripedName[35];
        // strncpy copies at max 34 characters from original movie name to striped array
        strncpy(stripedName, movies[i].movieName, 34);
        // set the last element in the striped array to null character to end string
        stripedName[34] = '\0';

        // initialize array which represents copy of movie genre that will be striped to limit to 26 characters (including null character)
        char stripedGenre[26];
        // strncpy copies at max 25 characters from original movie genre to striped array
        strncpy(stripedGenre, movies[i].movieGenre, 25);
        // set the last element in the striped array to null character to end string
        stripedGenre[25] = '\0';

        // print movie code, title, genre and rating columns with formatting for alignment and spacing
        // movie code left aligned in 12 character wide column, movie name left aligned in 38 character wide column, 
        // movie genre left aligned in 27 character wide column, movie rating displayed with one decimal place
        printf("%-12d%-37s%-27s%.1f\n", movies[i].code, stripedName, stripedGenre, movies[i].movieRating);
    }
    // print newline after list to screen
    printf("\n");
}

// clearCharacter function clears characters from buffer (if exceeded maximum striped length)
void clearCharacters() {
    // declaration of character variable representing characters read from  buffer 
    int character;

    // read characters from buffer until meets new line or end of file
    while ((character = getchar()) != '\n' && character != EOF) ;
}

// searchMovie function searches for movie of specified code and print the movie and its information
void searchMovie(struct movie movies[], int code) {

    // prompt user to enter movie code
    printf("        Enter movie code: ");

    // read movie code from user and store in code variable and if code is invalid input then
    if (scanf("%d", &code) != 1) {
        // clear characters from buffer and return from function
        clearCharacters();
        return;
    } 
    // clear any remaining characters from buffer
    clearCharacters();

    // find index of movie with specified code in database
    int movieCodeIndex = find_movie(movies, code);

    // if the index is greater than 0 meaning if movie is found then print header with formatting specifiers
    if (movieCodeIndex >= 0) {
        printf("%-12s%-37s%-27s%-s\n", "Movie Code", "Movie Name", "Movie Genre", "Movie Rating");

        // initialize array which represents copy of movie name that will be striped to limit to 35 characters (including null character)
        char strippedName[36];
        // strncpy copies at max 34 characters from original movie name to striped array
        strncpy(strippedName, movies[movieCodeIndex].movieName, 35);
        // set the last element in the striped array to null character to end string
        strippedName[35] = '\0';

        // initialize array which represents copy of movie genre that will be striped to limit to 26 characters (including null character)
        char strippedGenre[26];
        // strncpy copies at max 25 characters from original movie genre to striped array
        strncpy(strippedGenre, movies[movieCodeIndex].movieGenre, 25);
        // set the last element in the striped array to null character to end string
        strippedGenre[25] = '\0';

        // print movie details with formatting specifiers
        printf("%-12d%-37s%-27s%.1f\n", movies[movieCodeIndex].code, strippedName, strippedGenre, movies[movieCodeIndex].movieRating);
    
    // otherwise if movie is not found in database (index is -1) then print to screen that movie is not in database
    } else {
        printf("Movie with code %d is not in the database.\n", code);
    }
}

// updateMovie function updates movie details
void updateMovie(struct movie movies[], int numOfMovies) {
    // intialization of code variable storing movie code
    int code;

    // prompt user to enter movie code
    printf("        Enter movie code: ");

    // read movie code from user and store in code variable and if code is invalid input then
    if (scanf("%d", &code) != 1) {
        // clear characters from buffer and return from function
        clearCharacters();
        return;
    }
    // clear any remaining characters from buffer
    clearCharacters();

    // find index of movie with specified code in database
    int movieCodeIndex = find_movie(movies, code);

    // if the index is greater than 0 meaning if movie is found then print header with formatting specifiers
    if (movieCodeIndex >= 0) {

        // prompt user for movie name and call readString function to read movie name from user
        printf("        Enter movie name: ");
        readString(movies[movieCodeIndex].movieName, TOTAL_MOVIE_NAMES);

        // prompt user for movie genre and call readString function to read movie genre from user
        printf("        Enter movie genre: ");
        readString(movies[movieCodeIndex].movieGenre, TOTAL_MOVIE_GENRES);

        // prompt user for movie rating
        printf("        Enter movie rating: ");

        // read updated movie rating from user and if input invalid then clear characters from buffer and return from function
        if (scanf("%f", &movies[movieCodeIndex].movieRating) != 1) {
            clearCharacters();
            return;
        }
        // clear any remaining characters from buffer
        clearCharacters();
    }

    // otherwise if movie is not found in database (index is -1) then print to screen that movie is not in database
    else {
        printf("Movie with code %d is not in the database.\n", code);
    }
    
}

int main(void) {
    // print header to screen 
    printf("*********************\n* 2211 Movie Cinema *\n*********************\n\n");

    // declaration of array of movie structure with length TOTAL_MOVIE_NAMES (max movie names database can store) which stores movie information
    struct movie movies[TOTAL_MOVIE_NAMES];
    // declaration of operationCode variable storing operation code prompted by user
    char operationCode;

    // iteration through array of movie structure and set operation code for each movie structure to 0
    for (int i = 0; i < TOTAL_MOVIE_NAMES; i++) {
        movies[i].code = 0;
    }

    // infinite loop to execute program
    for (;;) {

        // prompt user for operation code then read users input and store in operationCode variable
        printf("Enter operation code: ");
        scanf(" %c", &operationCode);

        // clear any remaining characters in buffer
        while (getchar() != '\n');

        // using switch case to determine action that needs to be taken based on operation code
        switch (operationCode) {
            // if user entered i then call insertMovie function to insert a movie to database then return from function
            case 'i': insertMovie(movies);
                break;
            // if user entered s then call searchMovie function to search for movie in database (based on operationCode) then return from function
            case 's': searchMovie(movies, operationCode);
                break;
            // if user entered u then call updateMovie function to update movie details in database then return from function
            case 'u': updateMovie(movies, operationCode);
                break;
            // if user entered p then call printMovie function to print movie details then return from function
            case 'p': printMovie(movies);
                break;
            // if user entered q then end program
            case 'q': return 0;
            // otherwise, if user did not enter i, s, u, p, or q, then print to screen that incorrect operation code has been entered
            default: printf("Incorrect code. Please enter code i, s, u, p, or q.\n");
        }
        // print new line to screen
        printf("\n");
    }
}