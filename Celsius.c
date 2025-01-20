#include <stdio.h>

/*
Code for providing a table of Fahrenheit and Celsius conversions.
This code was provided in the book: The C Programming language by authors: Kernighan and Ritchie
*/

int main(){

int lower, upper, step;
float fahr, celsius;

lower = 0; /*Lower limit of the temperature table*/
upper = 300; /*Upper Limit*/
step = 20; /*Step size*/

fahr = lower;
printf("Fahrenheit\tCelsius\n");
while (fahr <= upper){
    celsius = (5.0/9.0) * (fahr-32.0);
    printf("%3.0f \t\t %6.1f\n", fahr, celsius);
    fahr = fahr + step;

}

return 0;
}
