/*
  Program to show the working and implementation of Linked List using strings
  Pranav
  1-12-2025
  linkedliststring.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListType {
  char Data[20];
  struct ListType *Next;
} LISTNODE;

LISTNODE *Head;

//prototype
void InitList();
void InsertNode(char str[20]);
void DisplayList(LISTNODE *Head);

int main (){
  int n, i;
  char str[20];

  InitList();

  printf("Program to enter elements in Linked List and display it\n");
  printf("Enter number of elements to be inserted: ");
  scanf("%d", &n);
  for(i=0; i<n; i++){
    printf("Enter the string(s): ");
    scanf("%s", str);
    InsertNode(str);
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
    printf(" '%s' -> ", Current->Data);
    Current = Current->Next;
  }
  printf("NULL\n");
}
void InsertNode(char str[20]){
  LISTNODE *Current, *Node;
  Node = (LISTNODE *)malloc(sizeof(LISTNODE));
  strcpy(Node->Data,str);
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