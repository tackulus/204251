//
// Assignment05.c
// 204251 Data Structure
//
// Kasidis Torcharoen
// 610510531
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queueNode qNode;

struct queueNode
{
    int item;
    qNode* next;
};

// Global Variable
qNode* frontPtr=NULL;
qNode* backPtr=NULL;
int numNode = 0;

bool isEmpty() { return !numNode; }

int size() { return numNode; }

void toString() {

    qNode* cur=frontPtr;
    while (cur!=NULL) {
        printf("%d ", cur->item);
        cur = cur->next;
    }
    putchar('\n');
}

void enqueue(int item) {

    qNode* newPtr=(qNode*) malloc(sizeof(qNode));
    newPtr->item = item;
    newPtr->next = NULL;

    isEmpty() ? (frontPtr = newPtr) : (backPtr->next = newPtr);
    backPtr = newPtr;
    numNode++;
}

void dequeue() {

    if (isEmpty()) { return; }
    qNode* del=frontPtr;
    frontPtr = frontPtr->next;
    numNode--;
    if (isEmpty()) { backPtr = NULL; }
    free(del);
}

int getFront() { 
    
    if (isEmpty()) { return -1; }
    else { return frontPtr->item; }
}

void clearQueue() {

    if (isEmpty()) { return; }
    else {
        dequeue();
        clearQueue();
    }
}



int main() {

    int o, x;
    while (1) {
        scanf("%d", &o);
        switch (o) {
            case 1:
                scanf("%d", &x);
                enqueue(x);
                toString();
                break;
            case 2:
                dequeue();
                toString();
                break;
            case 3:
                printf("%d\n", getFront());
                break;
            case 4:
                clearQueue();
                toString();
                break;
            case 5:
                printf("%d\n", size());
                break;
            case 6:
                if (isEmpty()) { puts("yes"); }
                else { puts("no"); }
                break;
            case 7:
                exit(0);
        }
    }
    clearQueue();
    return 0;
}