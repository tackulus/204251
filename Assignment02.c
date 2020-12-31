//
// Assignment02.c
// 204251 Data Structure
//
// Kasidis Torcharoen
// 610510531
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node_D{
    struct node_D* prev;
    int    item;
    struct node_D* next;
};

typedef struct node_D NODE;
typedef NODE* LINK;

LINK header, trailer;

void generateDLL()
{
    header = (LINK) malloc(sizeof(NODE));
    trailer = (LINK) malloc(sizeof(NODE));
    header->prev = NULL;
    header->next = trailer;
    trailer->prev = header;
    trailer->next = NULL;
}

bool isEmpty()
{
    return (header->next == trailer);
}

int getSize(LINK cur)
{
    if (cur->next == trailer)
        return 0;
    else 
        return (1 + getSize(cur->next));
}

void insertFirst(int val)
{
    // create new node
    LINK ptr = (LINK) malloc(sizeof(NODE));
    ptr->item = val;

    // redirect link
    header->next->prev = ptr;
    ptr->prev = header;
    ptr->next = header->next;
    header->next = ptr;
}

void insertLast(int val)
{
    // create new node
    LINK ptr = (LINK) malloc(sizeof(NODE));
    ptr->item = val;

    // redirect link
    trailer->prev->next = ptr;
    ptr->next = trailer;
    ptr->prev = trailer->prev;
    trailer->prev = ptr;
}

void removeFirst()
{
    // empty list
    if (isEmpty())
        return;

    // locate node
    LINK del = header->next;

    // redirect link
    header->next = del->next;
    del->next->prev = header;

    // free memory
    free(del);
}

void removeLast()
{
    // empty list
    if (isEmpty())
        return;

    // locate node
    LINK del = trailer->prev;
    
    // redirect link
    trailer->prev = del->prev;
    del->prev->next = trailer;
    
    // free memory
    free(del);
}

void displayList()
{
    // empty list
    if (isEmpty())
        return;
    
    LINK cur=header->next;
    while (cur != trailer)
    {
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

void traverseList()
{
    int step, chr, i;
    LINK cur = header->next;
    scanf("%d", &step);
    
    for (i=1, i<=step, i++)
    {
        scanf("%c", &chr);
        
        // empty list
        if (cur == trailer)
            continue;
        
        else if (chr=='L')
        {
            // leftmost
            if (cur->prev == header)
                continue;
            
            else
                cur = cur->prev;
        }
        
        else if (chr=='R')
        {
            // rightmost
            if (cur->next == trailer)
                continue;
            
            else
                cur = cur->next;
    }

    if (cur == trailer)
        printf("no\n");
        
    else
        printf("%d\n", cur->item);
}

void freeAll()
{
    LINK cur = header;
    while (cur != NULL)
    {
        LINK next = cur->next;
        free(cur);
        cur = next;
    }
}

int main()
{
    generateDLL();
    int n, val;    
    do
    {
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                if (isEmpty())
                    printf("yes\n");
                else
                    printf("no\n");
                break;
            case 2:
                printf("%d\n", getSize(header));
                break;
            case 3:
                scanf("%d", &val);
                insertFirst(val);
                break;
            case 4:
                scanf("%d", &val);
                insertLast(val);
                break;
            case 5:
                removeFirst();
                break;
            case 6:
                removeLast();
                break;
            case 7:
                displayList();
                break;
            case 8:
                traverseList();
                break;
            case 9:
                exit(0);
        }
    } while (1);
    freeAll();
    return 0;
}
