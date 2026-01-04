/*
  Program to sort list using Bubble Sort
  Pranav
  5-1-2026
  bubble_sort.c
*/

#include<stdio.h>

void InputArray(int a[], int n);
void DisplayArray(int a[], int n);
void BubbleSort(int a[], int n);

int main(){
  int a[100], n;
  
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  InputArray(a, n);
  
  printf("\nUnsorted List: ");
  DisplayArray(a, n);
  
  BubbleSort(a, n);
  
  printf("\nSorted List (Bubble Sort): ");
  DisplayArray(a, n);
  
  return 0;
}

void InputArray(int a[], int n){
  int i;
  printf("Enter %d integers: ", n);
  for(i=0; i<n; i++){
    scanf("%d", &a[i]);
  }
}

void DisplayArray(int a[], int n){
  int i;
  for(i=0; i<n; i++){
    printf("%d ", a[i]);
  }
  printf("\n");
}

void BubbleSort(int a[], int n){
  int i, j, temp;
  
  for(i=0; i < n-1; i++){
    // Last i elements are already in place
    for(j=0; j < n-i-1; j++){
      if(a[j] > a[j+1]){
        // Swap
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
    }
  }
}