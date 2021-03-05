//
// Assignment07.c
// 204251 Data Structure
//
// Kasidis Torcharoen
// 610510531
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int MAXLENGTH = 10;
int heap[10];
int numElement = 0;

int parent(int i) { return (i-1)/2; }
int left(int i) { return 2*i+1; }
int right(int i) { return 2*i+2; }

bool isEmpty() { return numElement == 0; }

int min() {
    if (isEmpty()) { return -1; }
    return heap[0];
}

void showPriorityQueue() {
    int i = 0;
    while (i < numElement) { printf("%d ", heap[i++]); }
    printf("\n");
}

void Downheap(int i) {
    int ileast = i;
    int lchild = left(i);
    int rchild = right(i);
    if (lchild <= numElement)
        ileast = (heap[lchild] < heap[ileast]) ? lchild : ileast;
    if (rchild <= numElement)
        ileast = (heap[rchild] < heap[ileast]) ? rchild : ileast;
    if (ileast != i) {
        heap[i] ^= heap[ileast] ^= heap[i] ^= heap[ileast];
        Downheap(ileast);
    }
}

void Upheap(int i) {
    int p = parent(i);
    if (heap[p] > heap[i]) {
        heap[i] ^= heap[p] ^= heap[i] ^= heap[p];
        Upheap(p);
    }
}

void insert(int item) {
    heap[numElement] = item;
    Upheap(numElement++);
}

void removeMin() {
    if (isEmpty()) { return; }
    heap[0] = heap[--numElement];
    Downheap(0);
}

int main() {

    int o, x;
    while (1) {
        scanf("%d", &o);
        switch (o) {
            case 1:
                scanf("%d", &x);
                insert(x);
                showPriorityQueue();
                break;
            case 2:
                removeMin();
                showPriorityQueue();
                break;
            case 3:
                printf("%d\n", min());
                break;
            case 4:
                if (isEmpty()) { printf("yes\n"); }
                else { printf("no\n"); }
                break;
            case 5:
                exit(0);
        }
    }
    return 0;
}
