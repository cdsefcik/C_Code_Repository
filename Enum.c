#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

/*
*These were coding exercises done on "The Complete C Programming Bootcamp".
*Shows the use of data structure enum.
*Different data types, constant, hex format, I/O, unsigned variables, ternary operator, switch statement.
*Funcitons include selecting the max and getting the prime numbers.
*/

typedef enum{
    mon = 1,
    tue = 2,
    wed = 3,
    thur = 4,
    fri = 5,
    sat = 6,
    sun = 7

}WeekDays;

int main()
{


const short int moonLanding = 1969;
const float speedOfLight = 299792458;
const float pi1 = 3.142;
const int hexaDead = 0xDEAD;
const unsigned short int hexaSecret = 51966;  

    printf("Moonlanding: \n");
    printf("%10d \n",moonLanding);
    printf("%010d \n",moonLanding);
    printf("SpeedOfLight: \n");
    printf("%9.0f \n",speedOfLight);
    printf("%3E \n",speedOfLight);
    printf("Pi:");
    printf("%1.2f \n",pi1);
    printf("%+.1e \n",pi1);
    printf("HexaDead: \n");
    printf("%1E \n",hexaDead);
    printf("%1E \n",hexaDead);
    printf("hexaSecret: \n");
    printf("%1E \n",hexaSecret);
    printf("%1E \n",hexaSecret);

    float a, b, c;

    printf("Enter A operand: " );
    scanf("%f",&a);

    printf("Enter B operand: ");
    scanf("%f", &b);

    c = a + b;

    printf("The value of c =: %f ", c);

    c = a - b;
    
    printf("The value of c =: %f ", c);

    c = a * b;

    printf("The value of c =: %f ", c);

    c = a / b;

    printf("The value of c =: %f ", c);

    //c = a % b;

    //printf("The value of c =: %f ", c);

    
    
    
    uint8_t e = 12;
    uint8_t f = 12;

    printf("A & B = %u\n", e & f);

    int a1, b2=3;

    printf("b = %d\n",b2);

    a1 = b2;

    a1+=b2;

    printf("a: %d\n",a1);

    a -=b2;
    printf("a: %d\n",a1);

    
   
   int variable = 0;
    
    printf("%llu\n", sizeof(variable));
    printf("%llu\n", sizeof(int));
    printf("%llu\n", sizeof(long int));
    printf("%llu\n", sizeof(long long int));

    
   
    double radius;
    const float pi = 3.14159; 
    printf("Enter the radius: ");
    scanf("%lf", &radius);
    printf("\n");
    double area = pi*radius*2;
    double volume = radius*radius*pi;
    printf("The surface area is: %.2lf", area);
    printf("The volume area is: %.3lf", volume);
    
   
   unsigned int data = 0xABCD;
   unsigned int N = 4;
   unsigned int M = 7;

   unsigned result = (data >> N) & 0b1111;

   printf("Data -----> 0x%04X\n",data);
   printf("Data -----> 0x%04X\n",result);

   
    
    int value;
    bool evenOdd;

    printf("====Even or Odd Challenge: \n");
    printf("Enter a positive integer: ");
    scanf("%d",&value);

    if(value < 0){
        printf("The value is less than 0, exiting program \n");
        return 0;
    }else{
        if((value % 2) == 0){
        evenOdd = true;
        }else{
            evenOdd = false;
        }
    }

    (evenOdd) ? printf("Even") : printf("Odd");

    

   
    int number = 5;
    switch(number){
    case 1:
        printf("1");
        break;
    case 5:
        printf("5");
        break;
    case 10:
        printf("10");
        break;
    default:

    }
    

   
    enum days;

    

    printf("\n\n=== Days of the week === \n\n");
    
    printf("Monday/Sunday: %d/%d\n", mon, sun);

    WeekDays day;
    printf("Enter a day of the week: ");
    scanf("%u", &day);

    switch(day){
        case mon:
        printf("The day is monday", day);
        break ;
        case tue:
        printf("The day is tue", day);
        break;
        case wed: 
        printf("The day is wed", day);
        break;
        case thur:
        printf("The day is thur", day);
        break;
        case fri:
        printf("The day is fri", day);
        break;
        case sat:
        printf("The day is sat", day);
        break;
        case sun:
        printf("The day is sun", day);
        break;
        default:
        printf("Wrong", day);
        break;
    }
    
   printf("\n");
   
   int compare;
   int iterations = 2;

   printf("Enter an integer: ");
   scanf("%d",&compare);

    if(compare < 0){
        printf("The number is less than 0: \n");
        return 0;
    }

    while(iterations < compare){
        iterations = iterations << 1; //Or use iterations *= 2;
    }

    printf("The smallest power of 2 is %d", iterations);
    
   
   const char symbol = 'X';
   const int BASE_WIDTH = 10;
   const int TIP_WIDTH = 5;

   for(int i = 0; i < BASE_WIDTH; i++){
    printf("%c", symbol);
   }

   for(int i = 0; i < TIP_WIDTH; i++){
    for(int j = 0; j < i;j++){
        printf(" ");
    }
    printf("X\n");
   }
    int a3,b3,c3;

    printf("Enter the orbit in days for the three planets: ");
    scanf("%d",&a3);
    scanf("%d",&b3);
    scanf("%d",&c3);
    printf("\n");
    printf("Summary: %d, %d, %d", a3, b3, c3);

    int max;
    max = a3 > b3 ? a3: b3;
    max = c3 > max ? c3 : max;

    int lcm = -1;
    const int MAX_ITER = 10000;
     
    for(int i = 1; i < MAX_ITER; i++){
        int mul = max * i;
        if(mul % a3 == 0 && mul % b3 == 0 && mul % c3 == 0){
            lcm = mul;
            break;
        }
    }

    if(lcm == -1){
        printf("Exceeded the number of iterations");
    }else{
        printf("ORbits a, b, c align every %d days", lcm);
        printf("Planet a completes %d orbits\n", lcm / a3);
        printf("Planet a completes %d orbits\n", lcm / b3);
        printf("Planet a completes %d orbits\n", lcm / c3);
    }

    
   
   const int MAX = 1000;

   //Find all prime numbers up until upper limit: //
   int upperLimit;
   printf("Enter the limit: ");
   scanf("%d", &upperLimit);

   if(upperLimit < 2 || upperLimit > MAX){
    printf("Error: must be 2 < limit < MAX\n");
    goto exit_program;
   }

   for(int number = 2; number < upperLimit; number++){
    bool isPrime = true;
    for(int i = 2; i < number; i++){
       if(number % i == 0){
        isPrime = false;
        break;
       } 
    }

    if(isPrime){
        printf("%d\n", number);
    }
   }
    
    exit_program:
    printf("Exit Program");  

    return EXIT_SUCCESS;
}
