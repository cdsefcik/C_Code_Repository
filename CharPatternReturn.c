#include<stdio.h>

/*
This program is from "The C Programming Language by K&R.

When the program starts, it takes input from the user then repeats the line if it matches the char pattern.

*/

#define MAXLINE 1000 /*Maximum input line length */

int get_line(char line[], int max); /**/

int strindex(char source[], char searchfor[]);

char pattern[] = "ould"; /*Pattern to search for */

/*find all lines matching the pattern */

int main(void) {
	char line[MAXLINE];
	int found = 0;

	while(get_line(line,MAXLINE)> 0)
		if (strindex(line, pattern) >= 0) {
			printf("%s", line);
			found++;
		}
	return found;
}

/*getline: get line into s, return */
int get_line(char s[], int lim) {

	int c = 0 , i;

	i = 0;
	while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';
	return i;
}

/*strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[]) {

	int i, j, k;

	for (i = 0; s[i] != '\0'; i++) {
		for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
			;
		if (k > 0 && t[k] == '\0')
			return i;
	}
	return -1;

}
