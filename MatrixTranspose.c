#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>

/*
*The program is a demonstration from The Complete C Programming Bootcamp.
*This program asks the use to enter a set number of columns and rows, and the limit of numbers to randomly generate. Produces results.
*The results show the matrix and the transposed matrix.
*The program uses Macros, constants in variables, conditions and I/O.
*/


#define MIN_ROWS 2
#define MAX_ROWS 10
#define MIN_COLS 2
#define MAX_COLS 10
#define MIN_UPPER_LIMIT 2
#define MAX_UPPER_LIMIT 1000

void generate_matrix(const int rows, const int cols, int matrix[rows][cols], int upper_limit){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            matrix[i][j] = rand() % upper_limit;
        }
    }
}

void display_matrix(const int rows, const int cols, int matrix[rows][cols], bool transposed){
    for(int i = 0; i < (transposed ? cols: rows); i++){
        for(int j = 0; j < (transposed ? rows: cols); j++){
            printf("%4d", matrix[transposed ? j : i][transposed ? i : j]);
        }
        printf("\n");
    }

}

int main(){

    int rows, cols, upper_limit;
    
    printf("Enter the number of rows: ");
    scanf("%d",&rows);
    printf("\n");
    printf("Enter the numnber of columns: ");
    scanf("%d",&cols);
    printf("\n");
    
    if((rows < MIN_ROWS) || (rows > MAX_ROWS)){
        return EXIT_FAILURE;
    }

    if((cols < MIN_COLS) || (cols > MAX_COLS)){
        return EXIT_FAILURE;
    }
   printf("Enter the number of numbers: ");
   scanf("%d", &upper_limit);
   if(upper_limit > MAX_UPPER_LIMIT || upper_limit < MIN_UPPER_LIMIT){
    return EXIT_FAILURE;
   }
   
   int matrix[rows][cols];
   //Populate matrix

   srand(time(NULL)); //Resets the seed so that the output is different.
   generate_matrix(rows, cols, matrix, upper_limit);
   display_matrix(rows, cols, matrix, false);
   display_matrix(rows, cols, matrix, true);

 
    return EXIT_SUCCESS;
};
