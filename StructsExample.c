#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <string.h>

/*
*This is an introduction to structs.
*Defines the different ways a struct can be constructed.
*Note: This might not compile due to non constants in the arrays on Visual Studio. Compiles fine however using gcc-13.2.0.
*This also has pointers to structures. Uses the -> operator.
*Also covers structures as a return value.
*Covers pointers to structs along with allocating memory using malloc and sizeof.
*Has assigning values through pointers for a struct.
*Define and assignment of an array with literal values.
*/

#define MAX_DIMENSIONS 3

/*Struct Declarations*/
struct Guy{
char *name;
bool active;
int dimensions;
double pos[MAX_DIMENSIONS]; //Cannot use incomplete array,.....See flexible array member

};

//Aliasing the type with typedef (anonymous struct)
typedef struct
{
char *name;
bool active;
int dimensions;
double pos[MAX_DIMENSIONS]; //Cannot use incomplete array,.....See flexible array member
}GuyAnonymous;

//Aliasing the type with typedef (good practice)
typedef struct GuyType
{
char *name;
bool active;
int dimensions;
double pos[MAX_DIMENSIONS];
} GuyType;

typedef struct Motercycle{
    char * model;
    double speed;
    struct Guy owner;

}Motorcycle;

double calc_distance(int dimensions, double a[dimensions], double b[dimensions]){

    double square_distance = 0;
    for(int i = 0; i < dimensions; i++){
        square_distance += pow(a[i] - b[i], 2);
    }
    return sqrt(square_distance);
}

//Function to create bill
struct Guy create_bill(){
struct Guy bill = {
    .name = "Bill Gates",
    .pos = {1,2,3},
    .dimensions = 3,
    .active = true,
};
return bill;
};

struct Guy create_elon(){
struct Guy Elon = {
    .name = "Elon Musk",
    .pos = {3,2,1},
    .dimensions = 3,
    .active = true,
};
return Elon;
};

//Build a pointer to a struct
struct Guy *alloc_elon(){

struct Guy *elon = malloc(sizeof(struct Guy));

if (!elon){
    return NULL;
}

//Settings
elon->name = "Elon Musk";
elon->active = true;
elon->dimensions = 3;
double pos[] = {1,2,3};
memcpy(elon->pos, pos, sizeof(pos));

return elon;

}

int main(){
    
    //Implicit Initializations
    struct Guy elon2 = {
        "Elon Musk",
        false,
        3,
        {1,2,3}
    };

    //Explicit Initialization
    struct Guy elon3 = {
        .name = "Bill Gates",
        .pos = {3,2,1},
        .dimensions = 3,
        .active = true,
    };

    //Nested structure
    Motorcycle moto = {
        .model = "honda",
        .speed = 100,
        .owner = {
            .name = "Andrea",
            .dimensions = 3,
            .active = true,
            .pos = {0,0,0}
        }
    };

    

    struct Guy elon, bill;
    //Motorcycle moto;

    //Nested structure
    moto.model = "honda";
    moto.speed = 300;
    moto.owner.name = "Andrea";

    elon.name = "Elon Musk";
    elon.active = true;
    elon.dimensions = 3;
    elon.pos[0] = 1;
    elon.pos[1] = 2;
    elon.pos[2] = 3;
    
    bill.name = "Bill Gates";
    bill.active = true;
    bill.dimensions = 3;
    bill.pos[0] = 3;
    bill.pos[1] = 2;
    bill.pos[2] = 1;

    //Pointer to a structure
    struct Guy *pointerToGuy = &bill;

    printf("Guy's name: %s\n", (*pointerToGuy).name);
    printf("Guy's name: %s\n", pointerToGuy->name);

if(!elon.active || !bill.active){
    printf("%s isn't active now!\n", !elon.active ? elon.name : bill.name);
    return EXIT_FAILURE;
}

if(elon.dimensions != bill.dimensions){
    printf("%s and %s are in different dimensions!\n", elon.name, bill.name);
    return EXIT_FAILURE;
}

    printf("The distance between %s and %s is: %.1f\n",
    elon.name, bill.name, calc_distance(elon.dimensions, elon.pos, bill.pos));

//Structure as a return value:

struct Guy bill2 = create_bill();

    return EXIT_SUCCESS;
};
