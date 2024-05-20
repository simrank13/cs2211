#include <stdio.h>
#include <ctype.h>
/*
skullar5 - 251292956
This program converts measuring units. The program prompts user for user input asking them to specify what type of conversion they want (ex. kg to pounds)
and once user has specified what type of conversion they want (by choosing integer 1 to 4 (if user enters 5, that means they quit)), user is asked to enter a letter indicated in the instructions which will decide
the order of the conversion meaning for example K for kg to pounds and P for pounds to kg and once user entered character then user will be asked to enter a number they want
to get conversion and then program will return to the screen what the conversion of that value is with its unit (for example kg or pounds)
*/
int main(void) {
    // initialization of variable that will store user's input 
    int userInput;
    char userChar;
    float userValue;

    // while true (loop until user doesnt does not quit (program does not end))
    while(1) {
        // display conversion menu and prompt for user input
        printf("Please enter an integer between 1 to 5:\n1- conversion of kilograms and pounds\n2- conversion of hectares and acres\n3- conversion between litres and gallons\n4- conversion between kilometre and mile\n5- quit\nany other integer then try again: ");
        scanf("%d", &userInput);
        printf("You chose: %d\n", userInput);
        
        // if user enters 1 then ask for type of conversion (kg to lb or lb to kg)
        if(userInput == 1) {
            printf("Please enter K (for Kilograms to Pounds conversion) or P (for Pounds to Kilograms conversion): ");
            scanf(" %c", &userChar);

            // if user enters K meaning thye want conversion kg to lb, then prompt user to enter a value and convert that value to lbs by multiplying it with 2.24062 since 1 kg is 2.24062 lbs
            // then print to screen what conversion of user's value is 
            if(userChar == 'K') {
                printf("Please enter value (of kilograms) you want to convert into pounds: ");
                scanf("%f", &userValue);
                float poundValue = userValue * 2.20462;
                printf("Your conversion is: %f pounds\n", poundValue);

            }
            // if user enters P meeaning they want conversion lb to kg, then prompt user to enter a value and convert that value to kg by dividing it with 2.24062 since 1 lb is 1/2.24062 kg
            // then print to screen what conversion of user's value is 
            else if(userChar == 'P') {
                printf("Please enter value (of pounds) you want to convert into kilograms: ");
                scanf("%f", &userValue);
                float kilogramValue = userValue / 2.20462;
                printf("Your conversion is: %f kilograms\n", kilogramValue);

            }
            
        }
        // if user enters 2 then ask for type of conversion (hectares to acres or acres to hectares)
        else if(userInput == 2) {
            printf("Please enter H (for Hectares to Acres conversion) or A (for Acres to Hectares conversion): ");
            scanf(" %c", &userChar);

            // if user enters H meaning they want conversion hectares to acres, then prompt user to enter a value and convert that value to acres by multiplying it with 2.47105 since 1 hectare is 2.47105 acres
            // then print to screen what conversion of user's value is 
            if(userChar == 'H') {
                printf("Please enter value (of hectares) you want to convert into acres: ");
                scanf("%f", &userValue);
                float acresValue = userValue * 2.47105;
                printf("Your conversion is: %f acres\n", acresValue);

            }
            // if user enters A meaning they want conversion acres to hectares, then prompt user to enter a value and convert that value to hectares by dividing it with 2.47105 since 1 acre is 1/2.47105 hectare
            // then print to screen what conversion of user's value is 
            else if(userChar == 'A') {
                printf("Please enter value (of acres) you want to convert into hectares: ");
                scanf("%f", &userValue);
                float hectaresValue = userValue / 2.47105;
                printf("Your conversion is: %f hectares\n", hectaresValue);

            }
            
        }
        // if user enters 3 then ask for type of conversion (litres to gallons or gallons to litres)
        else if (userInput == 3) {
            printf("Please enter L (for Litres to Gallons conversion) or G (for Gallons to Litres conversion): ");
            scanf(" %c", &userChar);
            
            // if user enters L meaning they want conversion litres to gallons, then prompt user to enter a value and convert that value to gallons by mutliplying it with 0.264172 since 1 litre is 0.264172 gallon
            // then print to screen what conversion of user's value is 
            if(userChar == 'L') {
                printf("Please enter value (of litres) you want to convert into gallons: ");
                scanf("%f", &userValue);
                float gallonsValue = userValue * 0.264172;
                printf("Your conversion is: %f gallons\n", gallonsValue);

            }
            // if user enters G meaning they want conversion gallons to litres, then prompt user to enter a value and convert that value to litres by dividing it with 0.264172 since 1 gallon is 1/0.264172 litre
            // then print to screen what conversion of user's value is
            else if(userChar == 'G') {
                printf("Please enter value (of gallons) you want to convert into litres: ");
                scanf("%f", &userValue);
                float litresValue = userValue / 0.264172;
                printf("Your conversion is: %f litres\n", litresValue);

            }
            
        } 
        // if user enters 4 then ask for type of conversion (kilometre to mile or mile to kilometre)
        else if (userInput == 4) {
            printf("Please enter K (for Kilometre to Mile conversion) or M (for Mile to Kilometre conversion): ");
            scanf(" %c", &userChar);

            // if user enters K meaning they want conversion kilometres to miles, then prompt user to enter a value and convert that value to miles by mutliplying it with 0.621371 since 1 kilometre is 0.621371 mile
            // then print to screen what conversion of user's value is 
            if(userChar == 'K') {
                printf("Please enter value (of kilometres) you want to convert into miles: ");
                scanf("%f", &userValue);
                float milesValue = userValue * 0.621371 ;
                printf("Your conversion is: %f miles\n", milesValue);

            }
            // if user enters M meaning they want conversion miles to kilometres, then prompt user to enter a value and convert that value to miles by dividing it with 0.621371 since 1 mile is 1/0.621371 kilometre
            // then print to screen what conversion of user's value is 
            else if(userChar == 'M') {
                printf("Please enter value (of miles) you want to convert into kilometres: ");
                scanf("%f", &userValue);
                float kilometresValue = userValue / 0.621371 ;
                printf("Your conversion is: %f kilometres\n", kilometresValue);

            }
            
        }
        // if user enters 5 then let the user know they have quit and quit the program
        else if (userInput == 5) {
            printf("You have quit.\n");
            break;
        }
        // if user entered any integer other than 1 to 5 then prompt user to enter again
        else {
            printf("Incorrect input, try again.\n");
        }
    }
    // return 0 to end program
    return 0;
}
