/*
skullar5 - 251292956
This program asks user to enter a number between 0 to 99, 0 for quit and and will not convert to english words
for any integer less than 0 and greater than 999 or that contains a decimal (is a float number) but if user enters
an integer from 1 to 999, it will convert the value user entered in english words. For example, 999 is nine hundred
and ninety-nine and 18 is eighteen
*/
#include <stdio.h>

int main(void) {
    // intialize variable that will store number user entered
    int number;

    // while true (loop until user doesnt does not quit (program does not end))
    while (1) {
        // prompt user to enter value between 1 to 999 to translate to english words and 0 to quit
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf("%d", &number);
        printf("You chose: %d\n", number);

        // if user entered 0 then let user know they have quit and end program
        if(number == 0) {
            printf("You have quit.\n");
            break;
        }
        // if user entered between 1 to 999 then 
        if(number >= 1 && number <= 999) {
            printf("You entered the number ");
            // create arrays storing ones and tens in english terms
            char *ones[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
            char *tens[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
            
            // if user's value is between 1 to 19 then print the element at the index of the number user entered minues 1 since the index starts from 0 and the ones array starts from one
            if(number >= 1 && number <= 19) {
                
                printf("%s\n", ones[number - 1]);
                
            }
            // if user entered from 20 to 99 then print the elements in the array tens at index of the number divided by 10 which will give the first digit of the number minus by 2 since array starts from twenty and since indexes start at 0
            else if(number >= 20 && number <=99) {            
                printf("%s", tens[(number/10) - 2]);
                // if the number has a remainder (meaning number has ones) then take that remainder and return element at that remainder - 1 since arrays start at one and since indexes start at 0 
                if (number % 10 != 0) {
                    printf("-%s\n", ones[(number%10) - 1]);
                // otherwise print newline to screen
                } else {
                    printf("\n");
                }

            }
            // if user entered from 100 to 999 then print elements of ones array at index of number user entered divided by 100 which gives the first digit of the number - 1 since array starts at one and since indexes start at 0
            else if(number >= 100 && number <= 999) {
                printf("%s hundred", ones[(number/100) - 1]);
                
                // if number has remainder then that means that the number has ones and/or tens
                if(number % 100 != 0) {
                    printf(" and ");

                    // if remainder is between 1 to 19 then print the element of ones array at index of the remainder - 1 (since array starts at one and since indexes start at 0)
                    if(number % 100 >= 1 && number % 100 <= 19) {
                        printf("%s\n", ones[(number%100) - 1]);
                    } 
                    // otherwise
                    else {
                        // if remainder is not 1 to 19 (has tens and ones) then print element of tens array of first digit (since number % 100 will give last 2 digits of number dividing that by 10 will give the middle digit, the tens) minus 2 since array starts at twenty and indexes start from 0
                        if (number % 10 != 0) {
                            printf("%s", tens[((number%100)/10) - 2]);
                            // then if there is ones print hyphen followed by the last digit of the tens - 1 since array starts at one and indexes start from 0
                            printf("-%s\n", ones[(number%10) - 1]);
                        } else {
                            // otherwise if there are no ones and just tens the print print element of tens array of first digit (since number % 100 will give last 2 digits of number dividing that by 10 will give the middle digit, the tens) minus 2 since array starts at twenty and indexes start from 0
                            printf("%s", tens[((number%100)/10) - 2]);
                        }

                    }
                }
                // otherwise print newline to screen
                printf("\n");
                
            }
        }
        
    }
    //return 0 to end program
    return 0;
}
