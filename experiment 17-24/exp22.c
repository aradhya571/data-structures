#include <stdio.h>

void bubbleSort(int arr[], int size) {
    int temp, i, j;
    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                // Swapping elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
}   }   }   }


int main() {
    int size, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &size);

    int arr[size];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Performing bubble sort
    bubbleSort(arr, size);

    printf("Sorted array in ascending order: ");
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}
