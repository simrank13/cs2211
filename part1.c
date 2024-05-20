/*
skullar5 - 251292956
This program asks user for how many integer they will provide with minimum of 5 and maximum of 12 integers, 
prints the number use gave and size of array in byte, prompts user for list of integers, 
prints elements of array and their positions (part1), prints elements of array in reverse and their positions (part2), 
prints all even elements in array and their positions (part3), prints the sum of all values in array (part5),
elements of array in ascneding order and their positions (part6), 
and prints array with swapped first and last elements and their positions (part6)
*/
#include <stdio.h>

// method part1 prints elements of provided array and their positions 
void part1(int array[], int numInt) {
    // print part 1 header
    printf("Part 1:\n    Your array is:");
    // iterate through 0 to number of integers (users will be providing) - 1 (last index), 
    //and print the index and the element each time until reaches last index
    for(int i = 0; i < numInt; i++) {
        
        printf(" [%d] = %d", i, array[i]);

        // print ', ' until the last index
        if(i < numInt - 1) {
            printf(", ");
        }
    }
    // after iteration is done and have gone through array, print new line
    printf("\n");

}
// method part2 prints provided array in reverse and their positons
void part2(int array[], int numInt) {
    // print part 2 header
    printf("Part 2:\n    Your array in reverse is:");
    //iterate through the last index until the first index, 
    //and print index and element each time until reaches first index
    for(int i = numInt - 1; i >= 0 ; i--) {
        
        printf(" [%d] = %d", i, array[i]);

        //print ', ' until the first index
        if(i > 0) {
            printf(", ");
        }
    }
    // after iteration is done and have gone through array, print new line
    printf("\n");
}
// method part3 prints out all even elements in provided array and their positions
void part3(int array[], int numInt) {
    // print part 3 header
    printf("Part 3:\n    The even elements in the array is:");
    // initialize count variable to record number of even elements printed
    int count = 0;
    // iterate through first to last index of array
    // and if the element in the array is even and is divisible by 2 then 
    //print index and element each time until reaches last index or element is not even
    for (int i = 0; i < numInt; i++) {
        if (array[i] % 2 == 0) {
            // if not first even element then print comma with space
            if(count > 0) {
                printf(", ");
            }

            printf("[%d] = %d", i, array[i]);
            // increment count variable by 1 
            count++;
        }
    }
    // after iteration is done and have gone through array, print new line
    printf("\n");
}
// method part4 prints out the sum of all values in provided array
void part4(int array[], int numInt) {
    // initialization of sum variable which total sum of all values in array
    int sum = 0;
    // iterate through array and element to sum variable until reaches last index
    for(int i = 0; i < numInt; i++) {
        sum += array[i];
    }
    // print part 4 header and sum of elements to screen
    printf("Part 4:\n    The sum of all values in your array is: %d", sum);
    // after iteration is done and have gone through array, print new line
    printf("\n");
}
// method part5 prints elements of provided array in assending order and their positions
void part5(int array[], int numInt, int copyArr[]) {
    // print part 5 header
    printf("Part 5:\n    Your array in sorted order is:");
    // iterate through array and add elements to copyArr to make copu of original array in copyArr
    for (int i = 0; i < numInt; i++) {
        copyArr[i] = array[i];
    }
    // iterate through first to last index
    for (int i = 0; i < numInt; i++) {
        // iterate through elements i+1 to last index 
        for (int j = i + 1; j < numInt; j++) {
            // if copyArr[i] (current element) is greater than copyArr(next element) then swap elements
            if (copyArr[i] > copyArr[j]) {
                // create temp variable which swaps current and next element
                int temp = copyArr[i];
                copyArr[i] = copyArr[j];
                copyArr[j] = temp;
            }
        }
    }
    // initialize position variable which stores position of original array
    int position = 0;
    //iterate through copyArr array to find positions of sorted elements in original array
    for (int i = 0; i < numInt; i++) {
        for (int j = 0; j < numInt; j++) {
            // if current element in copyArr is same as element in original array then store its position
            if (copyArr[i] == array[j]) {
                position = j;
            }
        }
        // print original position and element in array and value in sorted order
        printf(" [%d] = %d", position, copyArr[i]);
        
        // print ', ' until the last index
        if (i < numInt - 1) {
            printf(",");
        }
    }
    // after iteration is done and have gone through array, print new line
    printf("\n");

}
// part6 method prints array with fitst and last element swapped
void part6(int array[], int numInt) {
    //print part 6 header
    printf("Part 6:\n    Your array with the first and last elements switched is:");
    // if at least 2 elements in array then swap first and last element of array using temp variable
    if(numInt > 1) {
        int temp = array[0];
        array[0] = array[numInt-1];
        array[numInt-1] = temp;
    }
    // iterate through array and print elements with their positions
    for(int i = 0; i < numInt; i++) {
        //if first element then print last element and last position
        if(i == 0) {
            printf(" [%d] = %d", numInt - 1, array[i]);
        }
        // if element is between the first and last index (but not the first and last index) then print current element with its postion 
        if(i > 0 && i < numInt - 1) {
            printf(" [%d] = %d", i, array[i]);
        }
        // if last element then print first element and first index 
        if(i == numInt - 1) {
            printf(" [%d] = %d", 0, array[i]);
        }
        // print ', ' until the last index
        if(i < numInt - 1) {
            printf(", ");
        }
    }
    // after iteration is done and have gone through array, print new line
    printf("\n");
}

int main(void) {
    // declare numOfIntegers variable which stores number of integers that user wants to process
    int numOfIntegers;
    // prompt user to enter number od integers they want to process
    printf("Please enter the number of integers to process: ");
    scanf("%d", &numOfIntegers);
    //declare 'a' array with size numOfIntegers
    int a[numOfIntegers];
    //declare copyArr array of same size of a (numIntegers), making copy of a
    int copyArr[numOfIntegers];
    //iterate through array and copy elements from a into copyArr making copyArr copy array of a
    for(int i = 0; i < numOfIntegers;i++) {
        copyArr[i] = a[i]; 
    }
    //if numOfIntegers is not between 5 and 12 (inclusive) then print message that there is not enough room in array providing size of array in bytes
    if(numOfIntegers >= 5 && numOfIntegers <= 12) {
        printf("    There is enough room in your array for %d integers (%d bytes)", numOfIntegers, sizeof(a));
    }
    //if numOfIntegers is between 5 and 12 (inclusive) then print message that there is enough room in array providing size of array in bytes and end program there 
    else {
        printf("    There is not enough room in your array for %d integers (%d bytes)\n\n", numOfIntegers, sizeof(a));
        return 1;
    }

    // print new line to screen
    printf("\n");
    // as user to enter their integers and iterate through the integers and store integers in array 
    printf("\nPlease enter your integers separated by spaces: ");
    for(int i = 0; i < numOfIntegers;i++) {
        scanf("%d",&a[i]);  
    }
    // print new line for formatring and call the functipns to display the information about array a
    printf("\n");
    part1(a,numOfIntegers);
    printf("\n");
    part2(a,numOfIntegers);
    printf("\n");
    part3(a,numOfIntegers);
    printf("\n");
    part4(a,numOfIntegers);
    printf("\n");
    part5(a,numOfIntegers,copyArr);
    printf("\n");
    part6(a,numOfIntegers);
    // return 0 to end program
    return 0;
}