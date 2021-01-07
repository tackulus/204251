//
// Assignment04_2.c
// 204251 Data Structure
//
// Kasidis Torcharoen
// 610510531
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node NODE;
typedef NODE* LINK;

struct node
{
    char item;
    LINK down;
};

LINK stack = NULL;

bool isEmpty()
{
    return (stack == NULL);
}

void push(char item)
{
    LINK newPtr = (LINK) malloc(sizeof(NODE));
    newPtr->item = item;
    newPtr->down = stack;
    stack = newPtr;
}

char pop()
{
    if (isEmpty())
        return '#';
    
    LINK del=stack;
    char chr=stack->item;
    stack = stack->down;
    free(del);
    return chr;
}

char top()
{
    if (isEmpty())
        return '#';
    else
        return (stack->item);
}

int precedence(char symbol)
{
    switch(symbol)
    {
        case '*':
        case '/': return 2;
        
        case '+':
        case '-': return 1;

        default : return 0; 
    }
}

void printPostfix(char* exps)
{
    int n=strlen(exps);
    char chr;
    while (n-->0)
    {
        chr = *exps++;
        
        switch (chr)
        {
            case '(':
                push(chr);
                break;
            case ')':
                while (top() != '(')
                    printf("%c", pop());
                pop();
                break;
            case '+':
            case '-':
            case '*':
            case '/':
                while (precedence(top()) >= precedence(chr))
                    printf("%c", pop());
                push(chr);
                break;
            default:
                printf("%c", chr);
        }
    }
    while (! isEmpty())
        printf("%c", pop());
}

int main()
{
    char* exps=(char*) malloc(100*sizeof(char));
    scanf("%s", exps);
    printPostfix(exps);
    return 0;
}