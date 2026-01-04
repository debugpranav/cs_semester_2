/*
  Program to perform Linear Search
  Pranav
  5-1-2026
  linear_search.c
*/

#include<stdio.h>

void InputArray(int a[], int n);
void DisplayArray(int a[], int n);
int LinearSearch(int a[], int n, int key);

int main(){
  int a[100], n, key, pos;
  
  printf("Enter number of elements: ");
  scanf("%d", &n);
  
  InputArray(a, n);
  
  printf("\nArray Elements: ");
  DisplayArray(a, n);
  
  printf("Enter element to search: ");
  scanf("%d", &key);
  
  pos = LinearSearch(a, n, key);
  
  if(pos != -1){
    printf("Element %d found at position %d\n", key, pos+1);
  } else {
    printf("Element %d not found in the list\n", key);
  }
  
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

int LinearSearch(int a[], int n, int key){
  int i;
  for(i=0; i<n; i++){
    if(a[i] == key){
      return i;
    }
  }
  return -1;
}