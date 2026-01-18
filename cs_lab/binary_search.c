/*
  Program to perform Binary Search
  Pranav
  18 Jan, 2026
  binary_search.c
*/

#include <stdio.h>

void InputArray(int A[], int n);
void PrintArray(int A[], int n);
void BubbleSort(int A[], int n);
int BinarySearch(int A[], int n, int SearchNum);

int main(){
    int n, A[50], found, SearchNum;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    InputArray(A, n);
    
    BubbleSort(A, n);
    
    printf("Sorted Array: ");
    PrintArray(A, n);

    printf("Enter number to be searched: ");
    scanf("%d", &SearchNum);

    found = BinarySearch(A, n, SearchNum);

    if(found != -1){
        printf("%d is found in the list at position %d.\n", SearchNum, found);
    }else{
        printf("%d is not found in the list.\n", SearchNum);
    }
    return 0;
}

void InputArray(int A[], int n){
    int i;
    printf("Enter %d elements: \n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }
}

void PrintArray(int A[], int n){
    int i;
    for(i = 0; i < n; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

void BubbleSort(int A[], int n){
    int i, j, temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-1-i; j++){
            if (A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            } 
        }
    }
}

int BinarySearch(int A[], int n, int SearchNum){
    int low, high, mid;
    
    low = 0;
    high = n - 1;

    while(low <= high){
        mid = (low + high) / 2;
        if(SearchNum == A[mid]){
            return mid+1;
        }
        else if (SearchNum < A[mid]){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return -1;
}