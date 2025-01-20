#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*
*This program work with macros.
*/

//#define MAX_DIMENSIONS 3
#define ARRAY_LEN 100

//Function like macros
#define CALC_ARRAY_LEN(x) (sizeof(x) / sizeof(x[0]))
#define MAX(a,b) ((a > b) ? a : b)

#define LOG_INFO 
#define BUFFER_SIZE 1024


int main(){
    
double array[ARRAY_LEN];

    printf("Array length: %d\n", ARRAY_LEN);

#undef ARRAY_LEN //Undefines the original value of the macro
#define ARRAY_LEN 999

    printf("New array len: %d\n", ARRAY_LEN);

    printf("Source file: \"%s\", %d\n",__FILE__,__LINE__);

    printf("Complilation time: %s\n",__TIME__);

    int array_len = CALC_ARRAY_LEN(array); //Gives the needed length of an array.

    printf("Calculated array len: %d\n", array_len);

    int a = -1, b = 5;

    printf("Max(A,B) %d\n",MAX(a,b));


    //Conditional directives
    #ifdef SOME_MACRO
        printf("SOME_MACRO exists\n");
    #endif

    #ifdef LOG_INFO
    printf("This is an INFO!\n");
    #else
    printf("I shouldn't log anything!\n");
    #endif

    #if BUFFER_SIZE > 1024
    printf("The buffer is huge, do something!\n");
    #else
    printf("The buffer is ok\n");
    #endif
    

    return EXIT_SUCCESS;
}
