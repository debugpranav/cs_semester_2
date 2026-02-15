/*
  Program to sort a list of numbers using Quick Sort technique (with Swap function)
  Pranav
  16 Feb, 2026
  quicksort.c
*/

#include <stdio.h>

void InputArray(int A[], int n);
void DisplayArray(int A[], int n);
void QuickSort(int A[], int low, int high);
int Partition(int A[], int low, int high);
void Swap(int *a, int *b);

int main(){
    int n, A[100];

    printf("--- Quick Sort Program ---\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    InputArray(A, n);

    printf("\nOriginal Array: ");
    DisplayArray(A, n);

    QuickSort(A, 0, n - 1);

    printf("Sorted Array:   ");
    DisplayArray(A, n);

    return 0;
}

void InputArray(int A[], int n){
    int i;
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }
}

void DisplayArray(int A[], int n){
    int i;
    for(i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void Swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void QuickSort(int A[], int low, int high){
    int pivotIndex;
    
    if(low < high){
        pivotIndex = Partition(A, low, high);
        
        QuickSort(A, low, pivotIndex - 1);
        QuickSort(A, pivotIndex + 1, high);
    }
}

int Partition(int A[], int low, int high){
    int pivot = A[low];
    int i = low;
    int j = high;

    while(i < j) {
        while(A[i] <= pivot && i <= high - 1) {
            i++;
        }

        while(A[j] > pivot && j >= low + 1) {
            j--;
        }

        if(i < j) {
            Swap(&A[i], &A[j]);
        }
    }
    Swap(&A[low], &A[j]);
    return j;
}