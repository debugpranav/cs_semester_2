/*
  Program to show the working and implementation of Linked List
  Pranav
  1-12-2025
  linkedlistbasic.c
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

int main (){
  int num, n, i;

  InitList();

  printf("Program to enter elements in Linked List and display it\n");
  printf("Enter number of elements to be inserted: ");
  scanf("%d", &n);
  for(i=0; i<n; i++){
    printf("Enter the numbers: ");
    scanf("%d", &num);
    InsertNode(num);
  }
  DisplayList(Head);
  return 0;
}
void InitList(){
  Head = NULL;
}

void DisplayList(LISTNODE *head){
  LISTNODE *Current;
  if(head == NULL){
    printf("List is empty\n");
    return;
  }
  Current = head;
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