
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>


/*
* Use of bool
* Use of enum
* Number Formatting
*/

typedef enum{
    TEA = 10,     //0
    COFFEE = 20,
    JUICE = 30,
    BEER = 40,    //3
} Menu;


int main()
{

    double dec = 1.234567;
    double worldPop = 7.801E9;
    double plankConstant = 6.626E-34;

    char c = 'A';

    int number = 56899;

    printf("%5.1f The dec Number \n", dec);
    printf("%4.1f The dec Number \n", dec);
    printf("%4f The dec Number \n", dec);
    printf("%12.1e The dec Number\n", worldPop);
    printf("Here is the number: %c \n",c);
    printf("Here is the number: %d \n",c);


    printf("Enter a character\n");

    c = getchar();

    printf("The characters are: %c  %9d \n", c);
    
    printf("Enter a character\n");

    c = getchar();

    printf("The characters are: %c  %9d \n", c);

    bool a = true;
    bool b = false;

    printf("Number %d %d", a, b);

    Menu mario = COFFEE;

    Menu andrea = BEER;

    printf("Mario ordered: ..... %c\n", mario);
    printf("Andrea ordered:...... %c\n", andrea);

    return EXIT_SUCCESS;
}
