//
// Assignment04.1.c
// 204251 Data Structure
//
// Kasidis Torcharoen
// 610510531
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int MAXSIZE = 10;
int s[10];
int t = -1;

bool isEmpty()
{
    return (t == -1);
}

void push(int item)
{
    s[++t] = item;
}

void pop()
{
    t = (isEmpty()) ? t : t-1;
}

int getTop()
{
    if (isEmpty())
        return -1;

    return s[t];
}

void clearStack()
{
    t = -1;
}

int size()
{
    return (t+1);
}

void toString()
{
    int i;
    for (i=t; i>-1; i--)
        printf("%d ", s[i]);
    printf("\n");
}

int main()
{
    int input, item;
    while (1)
    {
        scanf("%d", &input);
        switch (input)
        {
            case 1:
                scanf("%d", &item);
                push(item);
                toString();
                break;
            case 2:
                pop();
                toString();
                break;
            case 3:
                printf("%d\n", getTop());
                break;
            case 4:
                clearStack();
                toString();
                break;
            case 5:
                printf("%d\n", size());
                break;
            case 6:
                if (isEmpty())
                    printf("yes\n");
                else
                    printf("no\n");
                break;
            case 7:
                exit(0);
        }
    }
    return 0;
}
