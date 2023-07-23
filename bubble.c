#include <stdio.h>
#include <stdlib.h>


int main(int argc, char *argv[]) {
    int array[] = { 1, 3, 8, 2, 9, 2, 5, 6 };
    int n = sizeof(array)/sizeof(array[0]);
    for (int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // Algorithm

    for (int i=0; i < n; i++) {
        for (int j=0; j<n-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }

    // Algorithm end

    for (int i=0; i<n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}