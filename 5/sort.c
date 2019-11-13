#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

void printArray(int a[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf(i == size - 1 ? "%d": "%d, ", a[i]);
    }
    printf("]");
}


// zlozonosc n^2
int* bubbleSort(int a[], int size) {
    int temp;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size; j++) {
            if (a[j-1] > a[j]) {
                temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
    return a;
}

// zlozonosc nlogn do n^2
int* quickSort(int a[], int size) {
    if (size == 2) {
        if (a[0] > a[1]) {
            int temp = a[0];
            a[0] = a[1];
            a[1] = temp;
        }
        return a;
    } else if (size < 2) {
        return a;
    }
    // choose pivot
    int pivotIndex = size/2;
    // swap pivot with last element
    int temp = a[size-1];
    a[size-1] = a[pivotIndex];
    a[pivotIndex] = temp;


    // partition
    int i, j;
    for (i = 0, j = 0; i<(size-1); i++) {
        if (a[i] < a[size - 1]) {
            temp = a[j];
            a[j] = a[i];
            a[i] = temp;
            j++;
        }
    }
    // swap pivot with last element
    temp = a[j];
    a[j] = a[size-1];
    a[size-1] = temp;

    quickSort(a, j);
    quickSort(a+j+1, size-(j+1));
    return a;
}


int main() {
    srand(time(NULL));
    int r,
            size = 14000;
    int a[size], b[size];
    for (int i = 0; i < size; i++) {
        r = rand();
        a[i] = r;
        b[i] = r;
    }
    printf("wygenerowano\n");

    printf("quickSort\n");
    clock_t qe, qs = clock();
    quickSort(a, size);
    qe = clock();
    printf("Czas quickSort: %ld\n", qe-qs);


    printf("bubbleSort\n");
    clock_t be, bs = clock();
    bubbleSort(a, size);
    be = clock();
    printf("Czas bubbleSort: %ld\n", be-bs);


}