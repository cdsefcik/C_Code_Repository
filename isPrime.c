#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
*Prints all the numbers up to a certain max.
*Good use of bool.
*Multiple functions within a program.
*Conditional statements.
*I/O in c
*/

const int MAX = 1000;

void printLimitError(){
    printf("Error: must be 2 < limit < MAX\n");
}

bool isOutofBounds(int limit){
    return (limit < 2 || limit > MAX);  
}

bool isPrime(int number){
    bool prime = true;
    for(int i = 2; i < number; i++){
        if(number % i == 0){
            return false;
        }
    }
    return prime;
}

int main()
{
    printf("*********Prime Numbers Improved************\n");

    int upperLimit;
    printf("Enter the upper limit: ");
    scanf("%d", &upperLimit);

    printf("\n");
    
    if(isOutofBounds(upperLimit)){
        printLimitError();
        return EXIT_FAILURE;
    }
    
    printf("Prime numbers up to %d: \n", upperLimit);

    for(int number = 2; number < upperLimit; number++){
        if(isPrime(number)){
            printf("%d\n", number);
        }
    }

    return EXIT_SUCCESS;
}
