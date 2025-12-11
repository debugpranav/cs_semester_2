/*
  Program to delete a specific node from a Linked List (Fixed)
  Pranav
  5-12-2025
  deletenode.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct ListType {
  int Data;
  struct ListType *Next;
} LISTNODE;

LISTNODE *Head;

//prototype
void InitList();
void InsertNode(int num);
void DisplayList(LISTNODE *head);
int DeleteGivenNode(int num);

int main (){
  int num, n, i, delValue, status;

  InitList();

  printf("Program to create a list and delete a specific node\n");
  printf("Enter number of elements to be inserted: ");
  scanf("%d", &n);
  
  for(i=0; i<n; i++){
    printf("Enter the numbers: ");
    scanf("%d", &num);
    InsertNode(num);
  }
  
  printf("\nOriginal List:\n");
  DisplayList(Head);

  printf("\nEnter the number to delete: ");
  scanf("%d", &delValue);

  status = DeleteGivenNode(delValue);

  if(status == 1){
    printf("\nNumber %d deleted successfully.\n", delValue);
    printf("\nList after deletion:\n");
    DisplayList(Head);
  } else {
    printf("Operation Failed: Number %d not found or List is empty.\n", delValue);
  }

  return 0;
}

void InitList(){
  Head = NULL;
}

void DisplayList(LISTNODE *Head){
  LISTNODE *Current;
  if(Head == NULL){
    printf("List is empty\n");
    return;
  }
  Current = Head;
  while(Current != NULL){
    printf("%d -> ", Current->Data);
    Current = Current->Next;
  }
  printf("NULL\n");
}

void InsertNode(int num){
  LISTNODE *Current, *Node;
  Node = (LISTNODE *)malloc(sizeof(LISTNODE));
  Node->Data = num;
  Node->Next = NULL;

  if(Head == NULL){
    Head = Node;
    return;
  }
  Current = Head;
  while(Current->Next != NULL){
    Current = Current->Next;
  }
  Current->Next = Node;
}

int DeleteGivenNode(int num){
  LISTNODE *Current, *Previous;

  // Case 1: List is empty
  if(Head == NULL){
    return -1;
  }

  // Case 2: The node to delete is the Head
  if(Head->Data == num){
    Current = Head;
    Head = Head->Next; 
    free(Current);
    return 1;
  }

  // Case 3: Traverse to find the node
  Current = Head;
  Previous = NULL;
  while(Current != NULL && Current->Data != num){
    Previous = Current;
    Current = Current->Next;
  }

  if(Current == NULL){
    return -1;
  }

  Previous->Next = Current->Next;
  free(Current);
  return 1;  
}