/*
  Program to perform Linear Search using Linked List
  Pranav
  5-1-2026
  linkedlist_linsearch.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct ListType {
  int Data;
  struct ListType *Next;
} LISTNODE;

LISTNODE *Head;

// Prototype
void InitList();
void InsertNode(int num);
void DisplayList(LISTNODE *head);
int LinearSearch(int key);

int main (){
  int choice, num, key, pos;

  InitList();

  while(1){
    printf("\n--- Linear Search (Linked List) Menu ---\n");
    printf("1. Insert Element\n");
    printf("2. Display List\n");
    printf("3. Search for an Element (Linear Search)\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter the number to insert: ");
        scanf("%d", &num);
        InsertNode(num);
        break;
        
      case 2:
        DisplayList(Head);
        break;
        
      case 3:
        printf("Enter the element to search: ");
        scanf("%d", &key);
        pos = LinearSearch(key);
        
        if(pos != -1){
          printf("Element %d found at Position %d.\n", key, pos);
        } else {
          printf("Element %d not found in the list.\n", key);
        }
        break;
        
      case 4:
        exit(0);
        
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

void InitList(){
  Head = NULL;
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

int LinearSearch(int key){
  LISTNODE *Current;
  int position = 1;

  if(Head == NULL){
    return -1;
  }
  
  Current = Head;
  while(Current != NULL){
    if(Current->Data == key){
      return position;
    }
    Current = Current->Next;
    position++;
  }
  
  return -1;
}