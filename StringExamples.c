#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //Used for analyzing strings.
#include <errno.h>
#include <string.h>

/*C strings example
    These examples are from The Complete C Programming Bootcamp on Udemy
 *  Building strings
 *  strlen
 *  strcpy
 *  strncpy
 *  strcmp
 *  strncmp
 *  strchr: locate first occurance of a character in string
 *  strstr: locate substring
 *  strtok: split a string into tokens: Seperate a string by delimiters.
 *
 */

#define BUF_SIZE 5 //Can use to get lines that are larger in size.

int find_all_occurrences(char str[], char c, int indexes[]){
    int found = 0;
    char *pstr = str;

    do
    {
        pstr = strchr(pstr, c);
        if(pstr){
            indexes[found++] = pstr - str;
        }
    } while (pstr);
    return found;
};

int tokenize_string(char str[], char delimiters[], int tok_max_len, char tokens[][tok_max_len]){
    
    int i;
    
    char *ptok = str;
;
    for(i = 0; ptok; i++){
        ptok = strtok(i == 0 ?  ptok : NULL, delimiters);
        strncpy(tokens[i],ptok,  ptok ? tok_max_len :  0);
    }
    
    return i-1;
};

void print_tokens(int n_tokens, int tok_max_len,  char tokens[][tok_max_len], char str[],const char delimiters){
    //printf("\n\nTokenization with delimiters \"%s\":\n",delimiters);
    //printf("%s\n", str);
    for(int i = 0; i < n_tokens; i++){
        printf("[%d] %s\n", i, tokens[i]);
    }
};

void clear_std_in(){
 int c = ' ';
 while (c != '\n' && c != EOF){
    c = getchar();
 }   
}

int get_line(char dst[], int size){
    int i;
    for(i = 0; i < size -1; i++){
        int c = getchar();
        if(c == '\n' || c == EOF){
            break;
        }else{
            dst[i] = (char)c;
        }
    }
    if (i == size -1){
        clear_std_in();
    }
    dst[i] = '\0';
    return i;
}

int main(){

    char my_string[] = "I love programming in c!";
    char mystring2[] = {'h','i'};

    /*String length from scratch*/
    int i;
    for(i = 0; my_string[i] != '\0'; i++);
    printf("String length (from scratch): %d\n",i);

    //Getting the size of the string. Overstates by one character due to the \0 character.
    printf("The size of operator: %d \n",sizeof(my_string));

    printf("The actual size of a string: %d \n",strlen(my_string));

    /*String copy: Should not use this strcpy due to copy limitations*/
    char another_string[] = "Programming is funny.";
    printf("Here is the first string: %s \n", my_string);
    printf("Here is the first string: %s \n", another_string);
    printf("Here is the first string: %s \n", strcpy(my_string, another_string));

    /*Use the strncpy, lets you set the number of elements to copy.*/
    char another_long_string[] = "This is a very long string used to test the new function";
    printf("Here is the first string: %s \n", my_string);
    printf("Here is the first string: %s \n", strncpy(my_string, another_long_string,sizeof(my_string)));
    printf("Here is the first string: %s \n", my_string);

    char str_1[] = "abcd";
    char str_2[] = "abczqwerty";

    printf("stringcmp %s %s %d \n",str_1,str_2,strcmp(str_1,str_2));
    printf("stringcmp %s %s %d \n",str_1,str_2,strncmp(str_1,str_2 ,4));

    //
    char str12[] = "this is a simple string";
    int occurences_indexes[sizeof(str12)];
    int found = find_all_occurrences(str12,'s',occurences_indexes);
    printf("Found: %d \n", found);

    //Split a string into tokens.
    //Strtok (char * str, const char * delimiters)

    char str20[] = "This, is a. sample-string";

    const char delimiters[] = ", .-";
    int tok_max_len = sizeof(str20);
    char tokens[tok_max_len][tok_max_len], str_cpy[tok_max_len];
    strncpy(str_cpy, str20, tok_max_len);
    int n_tokens = tokenize_string(str20, ", .-",tok_max_len,tokens);
    printf("\n");
    print_tokens(n_tokens, tok_max_len, tokens, str20, delimiters);

    //Used to test characters.
    char character = 'C';
    int characterNumber = (int)character;
    printf("Here are the characters: %c %d \n",character,characterNumber );
    int value1 = islower(characterNumber); //checks if lowercase letter
    int value2 = isupper(characterNumber); //checks if uppercase
    int value3 = isalpha(characterNumber); //checks is alphabetic
    int value4 = isalnum(characterNumber); //checks is alphanumeric
    int value5 = isdigit(characterNumber); //checks if decimal digit
    int value6 = isxdigit(characterNumber); //checks if hex digit
    int value7 = iscntrl(characterNumber); //checks if c is a control character
    int value8 = isprint(characterNumber); //checks if c is a printable character
    int value9 = isgraph(characterNumber); //checks if c is printable excluding spaces
    int value10 = isspace(characterNumber); //checks if c is white-space
    int value11 = ispunct(characterNumber); //checks if c is a punctuation character
    int value12 = tolower(characterNumber); //converts to lowercase
    int value13 = toupper(characterNumber); //converts to uppercase
    /*These are examples*/
    int atoi(const char *str); //converts str to an integer(int)
    long int atol(const char *str); //converts string to long int
    double atof(const char *str); // converts string to double
    double strtod(const char *str, char **endptr); //converts a str to a double
    long int strtol(const char *str, char **endptr, int base); //converts str to a long integer (long int)
    /*Examples End*/
    printf("Test functions: %d, %d \n", value1, value2);

    char str[] = "123";
    char *pend;

    long num = strtol(str, &pend, 10);

    printf("Here is the number: %ld", num);
    printf("\n");

    //Get the line function.
    char buffer[BUF_SIZE];

    do{
        printf("Enter a line: (Enter END to complete.) \n");
        int n = get_line(buffer, BUF_SIZE);
        printf("[%d] %s\n", n, buffer);
    }while (strcmp(buffer, "END"));

    return EXIT_SUCCESS;
}
