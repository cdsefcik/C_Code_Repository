
#define _CRT_SECURE_NO_WARNINGS  //Comment out if the program is not compiled on Windows.

#include <stdio.h>
#include <stdlib.h>

#define SAMPLES_LEN 100
#define DOWNSAMPLE_K 10




/*
 * This program goes over file I/O.
 * These functions and I/O can be found at cppreference.com.
 */

void program_failure(const char* str)
{
    perror(str);      // Prints the supplied message followed by the system error.
    exit(EXIT_FAILURE);
}

int main(void)
{
    /*------------------------------------------------------------
      Read and display a text file
    -------------------------------------------------------------*/

    FILE* fp1 = fopen("Test.txt", "r");
    if (fp1 == NULL)
    {
        perror("File opening failed");
        return EXIT_FAILURE;
    }

    int c;      // Must be int because fgetc() returns EOF (-1).

    while ((c = fgetc(fp1)) != EOF)
    {
        putchar(c);
    }

    printf("\n");

    if (ferror(fp1))
    {
        puts("I/O error when reading.");
    }
    else if (feof(fp1))
    {
        puts("End of file reached successfully.");
    }

    if (fclose(fp1) == EOF)
    {
        program_failure("Error closing Test.txt");
    }

    /*
        Note:
        fread() and fwrite() are generally preferred for binary files.

        Useful positioning functions:
            ftell()
            fgetpos()
            fseek()
            fsetpos()
            rewind()
    */

    /*------------------------------------------------------------
      Create sample data
    -------------------------------------------------------------*/

    printf("\n******************** Working with files ********************\n");

    double samples[SAMPLES_LEN];

    for (int i = 0; i < SAMPLES_LEN; i++)
    {
        samples[i] = (i + 1) / 10.0;
        printf("%.1f ", samples[i]);
    }

    printf("\n-----\n");

    /*------------------------------------------------------------
      Write samples to a binary file
    -------------------------------------------------------------*/

    FILE* fp = fopen("samples.bin", "wb");

    if (fp == NULL)
    {
        program_failure("File opening failed");
    }

    size_t written_count =
        fwrite(samples, sizeof(samples[0]), SAMPLES_LEN, fp);

    if (written_count != SAMPLES_LEN)
    {
        program_failure("File writing failed");
    }

    if (fclose(fp) == EOF)
    {
        program_failure("Error closing samples.bin after writing");
    }

    /*------------------------------------------------------------
      Read every 10th sample:
      sample 9, 19, 29, ..., 99
    -------------------------------------------------------------*/

    double sam_k[SAMPLES_LEN / DOWNSAMPLE_K];

    fp = fopen("samples.bin", "rb");

    if (fp == NULL)
    {
        program_failure("File opening failed");
    }

    for (int i = 0; i < SAMPLES_LEN / DOWNSAMPLE_K; i++)
    {
        long offset = (long)(DOWNSAMPLE_K - 1) * sizeof(sam_k[0]);

        if (fseek(fp, offset, SEEK_CUR) != 0)
        {
            program_failure("File seeking failed");
        }

        size_t count = fread(&sam_k[i], sizeof(sam_k[0]), 1, fp);

        if (count != 1)
        {
            if (feof(fp))
            {
                program_failure("Unexpected end of file");
            }
            else
            {
                program_failure("Error reading the file");
            }
        }

        printf("%.1f ", sam_k[i]);
    }

    printf("\n");

    if (fclose(fp) == EOF)
    {
        program_failure("Error closing samples.bin after reading");
    }

    return EXIT_SUCCESS;
}
