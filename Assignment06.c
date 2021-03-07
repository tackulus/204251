//
// Assignment06.c
// 204251 Data Structure
//
// Kasidis Torcharoen
// 610510531
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void displayData(int arr[], int n) {
    int i;
    for (i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r, bool ASC) {

    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Create temp arrays
    int L[n1], R[n2];
    
    // Copy data to temp array
    for (i = 0; i < n1; i++) L[i] = arr[l + i];
    for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
    
    // Merge the temp arrays
    i = 0;
    j = 0;
    k = l;
    if (ASC) {
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }        
    }
    else {
        while (i < n1 && j < n2) {
            if (L[i] >= R[j]) arr[k++] = L[i++];
            else arr[k++] = R[j++];
        }
    }

    // Copy the remaining elements of L[]
    while (i < n1) arr[k++] = L[i++];
    
    // Copy the remaining elements of R[]
    while (j < n2) arr[k++] = R[j++];
}

void Sort_by_asc(int arr[], int l, int r) {

    if (r > l) {
        int m = (l + r) / 2;
        Sort_by_asc(arr, l, m);
        Sort_by_asc(arr, m+1, r);
        merge(arr, l, m, r, true);
    }
}

void Sort_by_desc(int arr[], int l, int r) {    

    if (r > l) {
        int m = (l + r) / 2;
        Sort_by_desc(arr, l, m);
        Sort_by_desc(arr, m+1, r);
        merge(arr, l, m, r, false);
    }
}

int Binary_search(int arr[], int l, int r, int key, bool ASC) {
    if (l > r) return -1;
    
    int m = (l + r) / 2;
    if (key == arr[m]) return m+1;
    bool COND = ASC ? (key < arr[m]) : (key > arr[m]);  
    if (COND) return Binary_search(arr, l, m-1, key, ASC);
    else return Binary_search(arr, m+1, r, key, ASC);
}

int Sequential_search(int arr[], int n, int key) {
    int i = 0;
    while (i < n) if (key == arr[i++]) return i;
    return -1;
}

int main() {

    int n;
    scanf("%d", &n);
    int arr[n];
    bool sorted = false, asc = false;
    int l = 0;
    int r = n-1;
    int i;
    for (i=0; i<n; i++) { scanf("%d ", &arr[i]); }
    int o, key;
    while (1) {
        scanf("%d", &o);
        switch (o) {
            case 1:
                scanf("%d", &key);
                int pos;
                if (sorted) pos = Binary_search(arr, l, r, key, asc);
                else pos = Sequential_search(arr, n, key);
                if (pos == -1) printf("no\n");
                else printf("%d\n", pos);
                break;
            case 2:
                Sort_by_asc(arr, l, r);
                sorted = asc = true;
                displayData(arr, n);
                break;
            case 3:
                Sort_by_desc(arr, l, r);
                sorted = true;
                asc = false;
                displayData(arr, n);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}