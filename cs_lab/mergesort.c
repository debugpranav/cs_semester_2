/*
  Program to sort a list of numbers using Merge Sort technique
  Pranav
  16 Feb, 2026
  mergesort.c
*/

#include <stdio.h>

void InputArray(int A[], int n);
void DisplayArray(int A[], int n);
void MergeSort(int A[], int low, int high);
void Merge(int A[], int low, int mid, int high);

int main() {
    int n, A[100];

    printf("--- Merge Sort Program ---\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    InputArray(A, n);

    printf("\nOriginal Array: ");
    DisplayArray(A, n);

    MergeSort(A, 0, n - 1);

    printf("Sorted Array:   ");
    DisplayArray(A, n);

    return 0;
}

void InputArray(int A[], int n) {
    int i;
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
}

void DisplayArray(int A[], int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void MergeSort(int A[], int low, int high) {
    int mid;
    
    if(low < high) {
        mid = (low + high) / 2;

        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        
        Merge(A, low, mid, high);
    }
}

void Merge(int A[], int low, int mid, int high) {
    int i = low;
    int j = mid + 1;
    int k = low;
    int Temp[100];

    while(i <= mid && j <= high) {
        if(A[i] <= A[j]) {
            Temp[k] = A[i];
            i++;
        } else {
            Temp[k] = A[j];
            j++;
        }
        k++;
    }

    while(i <= mid) {
        Temp[k] = A[i];
        i++;
        k++;
    }

    while(j <= high) {
        Temp[k] = A[j];
        j++;
        k++;
    }

    for(i = low; i <= high; i++) {
        A[i] = Temp[i];
    }
}