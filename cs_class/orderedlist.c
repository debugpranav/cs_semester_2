/*
  Program to show the working of Ordered Linked List
  Pranav
  4-12-2025
  orderedlist.c
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
void InsertListNode(int num);
void DisplayList(LISTNODE *Head);

int main (){
  int num, n, i;

  InitList();

  printf("Program to enter elements in Ordered Linked List and display it\n");
  printf("Enter number of elements to be inserted: ");
  scanf("%d", &n);
  for(i=0; i<n; i++){
    printf("Enter the numbers: ");
    scanf("%d", &num);
    InsertListNode(num);
  }
  DisplayList(Head);
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

void InsertListNode(int num){
  LISTNODE *Current, *Previous, *Node;
  //allocating memory and assigning values
  Node = (LISTNODE *)malloc(sizeof(LISTNODE));
  Node->Data = num;
  Node->Next = NULL;
  
  //Case 1: No List, make the incoming node the Head of the List
  if(Head == NULL ){
    Head = Node;
    return;
  }

  // Case 2: Data on the New Node is less than the Head of the List, make that node the head
  if(num <= Head->Data){
    Node->Next = Head;
    Head = Node;
    return;
  }

  //Case 3: Insert the New Node at an appropriate location, to do that traverse the list and enter the new node in between
  Current = Head;
  while(Current && num >= Current->Data){
    Previous = Current;
    Current = Current->Next;
  }
  
  Previous->Next = Node;
  Node->Next = Current;
}