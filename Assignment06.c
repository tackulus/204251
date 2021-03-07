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

int n, i;

void displayData(int arr[]) {

    for (i=0; i<n; i++) { printf("%d ", arr[i]); }
    printf("\n");
}

void merge_asc(int arr[], int temp[], int left, int mid, int right)
{
    int i, left_end, num_elements, tmp_pos;
    left_end = mid - 1;
    tmp_pos = left;
    num_elements = right - left + 1;
    while ((left <= left_end) && (mid <= right)) {
        if (arr[left] <= arr[mid]) {
            temp[tmp_pos] = arr[left];
            tmp_pos = tmp_pos + 1;
            left = left + 1;
        }
        else {
            temp[tmp_pos] = arr[mid];
            tmp_pos = tmp_pos + 1;
            mid = mid + 1;
        }
    }
    while (left <= left_end) {
        temp[tmp_pos] = arr[left];
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (mid <= right) {
        temp[tmp_pos] = arr[mid];
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }
    for (i = 0; i < num_elements; i++) {
        arr[right] = temp[right];
        right = right -1;
    }
}

void merge_desc(int arr[], int temp[], int left, int mid, int right)
{
    int i, left_end, num_elements, tmp_pos;
    left_end = mid - 1;
    tmp_pos = left;
    num_elements = right - left + 1;
    while ((left <= left_end) && (mid <= right)) {
        if (arr[left] >= arr[mid]) {
            temp[tmp_pos] = arr[left];
            tmp_pos = tmp_pos + 1;
            left = left + 1;
        }
        else {
            temp[tmp_pos] = arr[mid];
            tmp_pos = tmp_pos + 1;
            mid = mid + 1;
        }
    }
    while (left <= left_end) {
        temp[tmp_pos] = arr[left];
        left = left + 1;
        tmp_pos = tmp_pos + 1;
    }
    while (mid <= right) {
        temp[tmp_pos] = arr[mid];
        mid = mid + 1;
        tmp_pos = tmp_pos + 1;
    }
    for (i = 0; i < num_elements; i++) {
        arr[right] = temp[right];
        right = right -1;
    }
}

void Sort_by_asc(int arr[], int tmp[], int l, int r) {

    int m;
    if (r > l) {
        m = (l + r) / 2;
        Sort_by_asc(arr, tmp, l, m);
        Sort_by_asc(arr, tmp, m+1, r);
        merge_asc(arr, tmp, l, m+1, r);
    }
}

void Sort_by_desc(int arr[], int tmp[], int l, int r) {

    int m;
    if (r > l) {
        m = (l + r) / 2;
        Sort_by_desc(arr, tmp, l, m);
        Sort_by_desc(arr, tmp, m+1, r);
        merge_desc(arr, tmp, l, m+1, r);
    }
}

int main() {

    int o, arr[10000], tmp[10000];
    scanf("%d", &n);
    int l = 0;
    int r = n-1;
    for (i=0; i<n; i++) { scanf("%d ", &arr[i]); }

    while (1) {
        scanf("%d", &o);
        switch (o) {
            case 1:
                displayData(arr);
                break;
            case 2:
                Sort_by_asc(arr, tmp, l, r);
                displayData(arr);
                break;
            case 3:
                Sort_by_desc(arr, tmp, l, r);
                displayData(arr);
                break;
            case 4:
                exit(0);
        }
    }
    return 0;
}