/*
  Program to delete the last node of a Linked List
  Pranav
  5-12-2025
  deletelast.c
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
int DeleteLastNode();

int main (){
  int num, n, i, deletedData;

  InitList();

  printf("Program to create a list and delete the last node\n");
  printf("Enter number of elements to be inserted: ");
  scanf("%d", &n);
  
  for(i=0; i<n; i++){
    printf("Enter the numbers: ");
    scanf("%d", &num);
    InsertNode(num);
  }
  
  printf("\nOriginal List:\n");
  DisplayList(Head);

  // Perform Deletion
  deletedData = DeleteLastNode();
  
  if(deletedData != -1){
      printf("Deleted Value: %d\n", deletedData);
      printf("List after deleting last node:\n");
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

int DeleteLastNode() {
  LISTNODE *Current, *Previous;
  int num;
  
  // Case 1: Empty List
  if (Head == NULL){
    printf("no list\n");
    return -1;
  }

  // Case 2: Only one node in the list
  if (Head->Next == NULL){
    num = Head->Data;
    free(Head);
    Head = NULL;
    return num;
  }
  
  // Case 3: Traverse to the end
  Current = Head;
  while(Current->Next != NULL){
    Previous = Current;
    Current = Current->Next;
  }
  
  // Current is now the last node, Previous is the second to last
  num = Current->Data;
  Previous->Next = NULL; // Remove the link to the last node
  free(Current);         // Delete the last node
  
  return num;
}