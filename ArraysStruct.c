#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <math.h>

#define LEN 10

/*
 *This shows how to work with arrays of structures.
 *Uses multiple structs with functions.
 *Uses math functions along with sleep.
 */


typedef struct Sample{
    double temperature;
    time_t timestamp;
} Sample;

int rand_range_int(int min, int max){
    return rand() % (max - min + 1) + min;
}

double rand_range(double min, double max, int decimal_digits){
 double scale_factor = pow(10,decimal_digits);
 int scaled_min = round(min * scale_factor);
 int scaled_max = round(max * scale_factor);
 return rand_range_int(scaled_min, scaled_max) / scale_factor;
}

double get_temperature(){

return rand_range(20,25,1);

}

int main(){

    Sample samples[LEN];

    for(int i = 0; i < LEN; i++){
        printf("Sample %d...\n", i);
        samples[i].timestamp = time(NULL);
        samples[i].temperature = get_temperature();
        sleep(1);
    }

    //Print the examples
    printf("\n timestamp, time offset, temp\n");

    for(int i = 0; i < LEN; i++){
        printf("%lld, %lld, %5.1f\n",
        samples[i].timestamp,
        samples[i].timestamp - samples[0].timestamp,
        samples[i].temperature);

    }

    return EXIT_SUCCESS;
};
