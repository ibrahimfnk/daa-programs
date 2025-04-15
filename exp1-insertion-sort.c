#include<stdio.h>
#include<conio.h>

void insertionSort(int arr[], int n) {
    int i, j, key;
    for(j = 1; j < n; j++) {
        key = arr[j];
        i = j - 1;
        while(i >= 0 && arr[i] > key) {
            arr[i+1] = arr[i];
            i = i - 1;
        }
        arr[i+1] = key;
    }
}

void main() {
    int arr[20];
    int n, i, j;
    printf("Enter the no: of elements:");
    scanf("%d", &n);
    printf("Enter the elements");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertionSort(arr, n);

    for(j = 0; j < n; j++) {
        printf("%d", arr[j]);
    }
}