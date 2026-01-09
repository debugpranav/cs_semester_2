/*
  Program to sort list using Selection Sort
  Pranav
  5-1-2026
  selection_sort.c
*/

#include<stdio.h>

void InputArray(int A[], int n);
void DisplayArray(int A[], int n);
void SelectionSort(int A[], int n);

int main(){
  int A[100], n;
  
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  InputArray(A, n);
  
  printf("\nUnsorted List: ");
  DisplayArray(A, n);
  
  SelectionSort(A, n);
  
  printf("\nSorted List (Selection Sort): ");
  DisplayArray(A, n);
  
  return 0;
}

void InputArray(int A[], int n){
  int i;
  printf("Enter %d integers: ", n);
  for(i=0; i<n; i++){
    scanf("%d", &A[i]);
  }
}

void DisplayArray(int A[], int n){
  int i;
  for(i=0; i<n; i++){
    printf("%d ", A[i]);
  }
  printf("\n");
}

void SelectionSort(int A[], int n){
  int min, loc, i, j;
  for(i=0; i<n-1; i++){
    min = A[i];
    loc = i;
    for(j=i+1; j<n; j++){
      if(A[j] < min){
        min = A[j];
        loc = j;
      }
    }
    A[loc] = A[i];
    A[i] = min;
  }
}