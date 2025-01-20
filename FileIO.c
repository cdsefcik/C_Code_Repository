#include <stdio.h>
#include <stdlib.h>

#define SAMPLES_LEN 100
#define DOWNSAMPLE_K 10

/*
*This program goes over file I/O.
*These funcitons and I/O can be found at cppreference.com
*/

void program_failure(char str[]){
    perror(str); //returns the error message
    exit(EXIT_FAILURE);
}


int main(void){

    //File pointer. This represents the file abstraction.
    FILE *fp1 = fopen("Test.txt", "r");
    if(!fp1){
        perror("File opening failes");
        return EXIT_FAILURE;
    }

    int c; //Used to handle the EOF
    while ((c = fgetc(fp1)) != EOF){
        putchar(c);
    }

    printf("\n");

    if(ferror(fp1)){
        puts("I/O error when reading");
    }else if(feof(fp1)){
        puts("End of file reached successfully");
    }

    fclose(fp1);

    //Note, fread is a preferred method to get files.

    //Note, fwrite takes a file stream, writes to another file and returns the size.

    //Moving within the files: 
    //ftell: Returns the current position indicator
    //fgetpos: gets the position indicator
    //fseek: Moves the file position indicator to a specific location in the file
    //fsetpos: moves the file position indicator to a specific location in a file
    //rewind: moves the file position indicator to the beginning in a file

    //WORKING WITHIN A FILE EXAMPLE
    printf("********************Working in files********************\n");
    
    double samples[SAMPLES_LEN];
    for(int i = 0; i < SAMPLES_LEN; i++){
        samples[i] = (i + 1) / 10.0;
        printf("%.1f, ", samples[i]);
    }

    printf("\n-----\n");

    FILE *fp = fopen("samples.bin", "wb");
    if(!fp){
        program_failure("File opening error");
    }

    size_t written_count = fwrite(samples, sizeof(samples[0]), SAMPLES_LEN, fp); //Assigns the result to the written_count variable. size_t is a data type that stores the result from the size of function.
    if(written_count != SAMPLES_LEN){
        program_failure("File writing failed");
    }
    fclose(fp);

    /*Read the samples from the file (index 9, 19...99)*/
    double sam_k[SAMPLES_LEN / DOWNSAMPLE_K];
    fp = fopen("samples.bin", "rb");

    for(int i = 0; i < SAMPLES_LEN / DOWNSAMPLE_K; i++){
        int offset = (DOWNSAMPLE_K - 1) * sizeof(sam_k[0]);
        if (fseek(fp, offset, SEEK_CUR) !=0){
            program_failure("file seeking failed");
        }
        size_t count = fread(&sam_k[i], sizeof(sam_k[0]), 1, fp);
        if(count != 1){
            if(feof(fp)){
                program_failure("Unexpected End Of File");
            }else{
                program_failure("Error reading the file");
            }
        }
        printf("%.1f, ", sam_k[i]);
    }

    return EXIT_SUCCESS;
}
