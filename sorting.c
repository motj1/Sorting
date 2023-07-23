#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        int i, j, k, n1 = m - l + 1, n2 = r - m, L[n1], R[n2];
        for (i = 0; i < n1; i++) L[i] = arr[l + i];
        for (j = 0; j < n2; j++) R[j] = arr[m + 1 + j];
        i = 0, j = 0, k = l;
        for (; i < n1 && j < n2; k++) { if (L[i] <= R[j]) { arr[k] = L[i]; i++; } else { arr[k] = R[j]; j++; } }
        for (; i < n1; arr[k] = L[i], i++, k++);
        for (; j < n2; arr[k] = R[j], j++, k++);
    }
}

void bubbleSort(int array[], int n) {
    for (int i=0; i < n; i++) {
        for (int j=0; j<n-1; j++) {
            if (array[j] > array[j+1]) {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main(void) {
    int size = 200000;
    int array[size];
    FILE *fp = fopen("in.txt", "r");
    for (int i=0; i<size; i++) fscanf(fp, "%d ", &array[i]); fclose(fp);
    mergeSort(array, 0, size-1);
    fp = fopen("out.txt", "w");
    for (int i=0; i<size; i++) fprintf(fp, "%d ", array[i]); fprintf(fp, "\n"); fclose(fp);
    return 0;
}