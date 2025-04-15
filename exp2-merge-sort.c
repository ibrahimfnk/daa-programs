#include<stdio.h>
#include<math.h>

void merge(int arr[], int start, int q, int end) {
    int k, i, j, n1, n2;
    n1 = q - start + 1;
    n2 = end -q;
    int left[n1+1];
    int right[n2+1];

    for(i = 0; i < n1; i++) {
        left[i] = arr[start+i];
    }

    for(j = 0; j < n2; j++) {
        right[j] = arr[q + j + 1];
    }

    left[n1+1] = 88888888;
    right[n2+1] = 88888888;

    i = 0;
    j = 0;
    for(k = start; k <= end; k++) {
        if (left[i] <= right[j]) {
            arr[k] = left[i++];
        } else {
            arr[k] = right[j++];
        }
    }
}

void mergesort(int arr[], int start, int end) {
    if (start < end) {
        int q = (start + end)/2;
        mergesort(arr, start, q);
        mergesort(arr, q + 1, end);
        merge(arr, start, q, end);
    }
}

int main() {
    int i, len;
    int arr[100];
    printf("Enter the length of the array: ");
    scanf("%d", &len);
    printf("Enter the elements of the array: ");
    for (i = 0; i < len; i++) {
    scanf("%d", &arr[i]);
    }
    mergesort(arr, 0, len - 1);
    printf("Sorted array: ");
    for (i = 0; i < len; i++) {
    printf("%d ", arr[i]);
    }
    return 0;
}