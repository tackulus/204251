//
// Assignment01.c
// 204251 Data Structure
//
// Kasidis Torcharoen
// 610510531
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node{
    int    item;
    struct node* next;
};

typedef struct node NODE;
typedef NODE* LINK;

LINK head = NULL;

bool isEmpty()
{
    return (head == NULL);
}

int getSize(LINK cur)
{
    if (cur == NULL)
        return 0;
    else 
        return (1 + getSize(cur->next));
}

LINK find(int index)
{
    LINK cur = head;
    int i;
    for (i=1; cur!=NULL && i<index; i++)
        cur = cur->next;
    return cur;
}

void insertList(int index, int val)
{
    // create new node
    LINK ptr = (LINK) malloc(sizeof(NODE));
    ptr->item = val;
    
    // if remove 1st node
    if (index == 1)
    {
        ptr->next = head;
        head = ptr;
        return;
    }

    LINK prev = find(index-1);
    // index out of bound
    if (prev == NULL)
        return;

    ptr->next = prev->next;
    prev->next = ptr;
}

void removeList(int index)
{
    // empty list
    if (head == NULL)
        return;

    LINK prev, del;

    // if remove 1st node
    if (index == 1)
    {
        del = head;
        head = head->next;
        free(del);
        return;
    }

    prev = find(index-1);

    // index out of bound
    if (prev == NULL || prev->next == NULL)
        return;

    del = prev->next;
    prev->next = del->next;
    free(del);
}

int retrieveList(int index)
{
    LINK cur = find(index);
    if (cur == NULL)
        return -1;
    else
        return (cur->item);
}

int findList(int val)
{
    LINK cur = head;
    int index = 1;
    while (cur != NULL)
    {
        if (cur->item == val)
        {
            return index;
        }
        cur = cur->next;
        index++;
    }
    return -1;
}

void displayList()
{
    // empty list
    if (head == NULL)
        return;
    
    LINK cur=head;
    while (cur != NULL)
    {
        printf("%d ", cur->item);
        cur = cur->next;
    }
    printf("\n");
}

void freeAll()
{
    LINK cur = head;
    while (cur != NULL)
    {
        LINK next = cur->next;
        free(cur);
        cur = next;
    }
}

int main()
{   
    int n, index, val, temp;
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
                printf("%d\n", getSize(head));
                break;
            case 3:
                scanf("%d", &index);
                scanf("%d", &val);
                insertList(index, val);
                break;
            case 4:
                scanf("%d", &index);
                removeList(index);
                break;
            case 5:
                scanf("%d", &index);
                temp = retrieveList(index);
                if (temp == -1)
                    printf("no\n");
                else
                    printf("%d\n", temp);
                break;
            case 6:
                scanf("%d", &val);
                temp = findList(val);
                if (temp == -1)
                    printf("no\n");
                else
                    printf("%d\n", temp);
                break;
            case 7:
                displayList();
                break;
            case 8:
                exit(0);
        }
    } while (1);
    freeAll();
    return 0;
}