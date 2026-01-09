/* Program to perform Insertion Sort
   Pranav
   8 Jan, 2026
   insertion_sort.c */

#include<stdio.h>

void InputArray (int A[], int n);
void InsertionSort (int A[], int n);
void DisplayArray (int A[], int n);

int main(){
    int n, A[100];

    printf("Program to perform Insertion Sort on an array of integers\n");
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    InputArray(A, n);
    
    InsertionSort(A, n);
    
    printf("Sorting completed successfully.\n");
    DisplayArray(A, n);
    return 0;
}

void InputArray (int A[], int n){
    int i;
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
}

void DisplayArray (int A[], int n){
    int i;
    printf("Array elements are:\n");
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void InsertionSort (int A[], int n){
    int x, i, j;

    for(i = 1; i < n; i++){
        x = A[i];
        j = i - 1;
        
        while(j >= 0 && A[j] > x){
            A[j+1] = A[j];
            j = j - 1;
        }
        A[j+1] = x;
    }
}