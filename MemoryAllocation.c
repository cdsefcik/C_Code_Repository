#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


/*
* Malloc: Allocates size bytes of uninitialized storage.
* Calloc: Allocates memory for an array of num objects of size and initializes all bytes in the storage to zero.
* Realloc: Re allocates a portion of memory. Must have been previously assigend using Malloc or Calloc.
* free: Frees the memory.
* This uses the memory allocation functions to get lines from the user.
*/

char *get_line_alloc(int *plen){
    if(!plen){ //Same as plan -- NULL

    //The use does not care about the length.
    plen = malloc(sizeof(*plen));
    if(!plen){
        //Cannot allocate memory... failure
        return NULL;
    }
    }
    *plen = 0;
    char *line = NULL;
    int buffer_size = 0, input;
    const int alloc_block_size = 5; //This will be the size of the buffer needed as the requirements grow.

    while(true){
       input = getchar();

       if(buffer_size <= *plen){
        buffer_size += alloc_block_size;
        char *realloc_line = realloc(line, buffer_size);

        if(!realloc_line){
            //Cannont do reallocation... failure.
            free(line);
            return NULL;
        }
        line = realloc_line;

       }

       if(input != '\n' && input != EOF){
        line[(*plen)++] = (char)input;
       } else{
        break;
       }
    }
    line[*plen] = '\0';
    return line;
}

int main(){

char *line = NULL; //pointer to where the line is stored
int len = -1;

do{
        printf("Enter a line (END to quit):\n");
        free(line);
        line = get_line_alloc(NULL);

        if(line){
            printf("%s ()\n",line);

        }else{
            printf("Cannot allocate memory\n");
        }

}while(line != NULL && strcmp(line, "END"));

    return EXIT_SUCCESS;
};
