/*
  Program to delete the first node of a Linked List
  Pranav
  5-12-2025
  deletefirst.c
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
int DeleteFirstNode();

int main (){
  int num, n, i, deletedData;

  InitList();

  printf("Program to create a list and delete the first node\n");
  printf("Enter number of elements to be inserted: ");
  scanf("%d", &n);
  
  // Create the list first
  for(i=0; i<n; i++){
    printf("Enter the numbers: ");
    scanf("%d", &num);
    InsertNode(num);
  }
  
  printf("\nOriginal List:\n");
  DisplayList(Head);

  // Perform Deletion
  deletedData = DeleteFirstNode();
  
  if(deletedData != -1){
      printf("Deleted Value: %d\n", deletedData);
      printf("List after deleting first node:\n");
      DisplayList(Head);
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

int DeleteFirstNode() {
  LISTNODE *Current;
  int num;
  
  if (Head == NULL){
    printf("no list\n");
    return -1;
  }
  
  Current = Head;
  num = Current->Data;    // Copy data before deleting
  Head = Head->Next;      // Move Head to the next node
  free(Current);          // Free the memory of the old Head
  
  return num;             // Return the deleted data
}