#include <stdio.h>
#include <stdlib.h>

#define SIZE 9

typedef struct element{
    int data;
    int numswaps;
} element;

element * numSwapsBubbleSort(int* arr, int size, int* totalSwaps) {
    *totalSwaps = 0;
    element* swaps = (element*)malloc(sizeof(element) * size);
    if (swaps == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
    swaps[i].data = arr[i];
    swaps[i].numswaps = 0;
    }
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (swaps[j].data > swaps[j + 1].data) {
                swaps[j].numswaps++;
                swaps[j + 1].numswaps++;
                element temp = swaps[j];
                swaps[j] = swaps[j + 1];
                swaps[j + 1] = temp;
                (*totalSwaps)++;
            }
        }
    }
    return swaps;
}

element* numSwapsSelectionSort(int* arr, int size, int* totalSwaps) {
    *totalSwaps = 0;
    element* swaps = (element*)malloc(sizeof(element) * size);
    if (swaps == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < size; i++) {
        swaps[i].data = arr[i];
        swaps[i].numswaps = 0;
    }
    for (int i = 0; i < size - 1; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (swaps[j].data < swaps[min].data) min = j;
        }
        if (i != min) {
            swaps[i].numswaps++;
            swaps[min].numswaps++;
            element temp = swaps[i];
            swaps[i] = swaps[min];
            swaps[min] = temp;
            (*totalSwaps)++;
        }
    }
    return swaps;
}

void printSwaps(element* swaps, int size, int totalSwaps) {
    for (int i = 0; i < size; i++) {
        printf("%d: %d times swapped\n", swaps[i].data, swaps[i].numswaps);
    }
    printf("Total number of swaps: %d\n", totalSwaps);
}

int main() {
    int array1[SIZE] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[SIZE] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int totalSwaps;

    printf("Bubble sort array1:\n");
    element* swapsBubble1 = numSwapsBubbleSort(array1, SIZE, &totalSwaps);
    printSwaps(swapsBubble1, SIZE, totalSwaps);
    free(swapsBubble1);

    printf("Selection sort array1:\n");
    element* swapsSelection1 = numSwapsSelectionSort(array1, SIZE, &totalSwaps);
    printSwaps(swapsSelection1, SIZE, totalSwaps);
    free(swapsSelection1);

    printf("Bubble sort array2:\n");
    element* swapsBubble2 = numSwapsBubbleSort(array2, SIZE, &totalSwaps);
    printSwaps(swapsBubble2, SIZE, totalSwaps);
    free(swapsBubble2);

    printf("Selection sort array2:\n");
    element* swapsSelection2 = numSwapsSelectionSort(array2, SIZE, &totalSwaps);
    printSwaps(swapsSelection2, SIZE, totalSwaps);
    free(swapsSelection2);

    return 0;
}