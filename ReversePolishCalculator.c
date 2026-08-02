#include <stdio.h>
#include <stdlib.h>  /** for atof() */
#include <ctype.h>

#define MAXOP 100 /*max size of operand or operator */
#define NUMBER '0' /*Signal that a number has been found*/

/*
This is from the K&R C book.
This is the reverse polish calculator example.
Enter  1 2 - 4 5 + * will equal -9
Enter 2 3 + will equal 5.

*/

int getop(char []);
void push(double);
double pop(void);

int getch(void);
void ungetch(int);

/*Reverse Polish Calculator */

int main(){

int type;
double op2;
char s[MAXOP];

while ((type = getop(s)) != EOF){
    switch(type){
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '*':
           push(pop() * pop());
           break;
        case '-':
            op2 = pop();          //Needs to be done to - and / as order is relevant.
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();          //Needs to be done to - and / as order is relevant.
            if(op2 != 0.0)
                push(pop() / op2);
            else    
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
    }


}

return 0;
}

#define MAXVAL 100 /*maximum depth of val stack */

int sp = 0;  /*next free stack position */
double val[MAXVAL] ;/*value stack */

/*push: push f onto value stack */
void push(double f){
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f); 

}

/*pop: pop and return top value from stack */
double pop(void){
    if(sp > 0)
        return val[--sp];
    else{
        printf("error: stack empty\n");
        return 0.0;
    }
}

/*getop: get next operator or numberic operand */
int getop(char s[]){
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if(!isdigit(c) && c != '.')
        return c;                          /*Not a number */
    i = 0;
    if(isdigit(c)) /*collect integer part */
        while (isdigit(s[++i] = c = getch()))
        ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch())) /*Collect fraction part */
        ;
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE]; /* buffer for ungetch */
int bufp = 0;      /* next free position in buf */

int getch(void){   /*get a (possibly pushed back) character */

    return (bufp > 0) ? buf[--bufp] : getchar();
}    

void ungetch(int c){ /* push character back on input*/

    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;

}
