/*
  Menu driven program for Ordered Linked List (Insert, Display, Search, Delete)
  Pranav
  8-12-2025
  orderedmenu.c
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
void InsertOrderedNode(int num);
void DisplayList(LISTNODE *head);
int SearchNode(int num);
int DeleteNode(int num);

int main (){
  int choice, num, status;

  InitList();

  while(1){
    printf("\n--- Ordered Linked List Menu ---\n");
    printf("1. Insert a number (Sorted)\n");
    printf("2. Display the list\n");
    printf("3. Search for a number\n");
    printf("4. Delete a number\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter the number to insert: ");
        scanf("%d", &num);
        InsertOrderedNode(num);
        break;
        
      case 2:
        DisplayList(Head);
        break;
        
      case 3:
        printf("Enter the number to search: ");
        scanf("%d", &num);
        status = SearchNode(num);
        if(status == 1)
          printf("Number %d found in the list.\n", num);
        else
          printf("Number %d not found.\n", num);
        break;
        
      case 4:
        printf("Enter the number to delete: ");
        scanf("%d", &num);
        status = DeleteNode(num);
        if(status == 1)
          printf("Number %d deleted successfully.\n", num);
        else
          printf("Number %d not found or List is empty.\n", num);
        break;
        
      case 5:
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

void InsertOrderedNode(int num){
  LISTNODE *Current, *Previous, *Node;
  
  Node = (LISTNODE *)malloc(sizeof(LISTNODE));
  Node->Data = num;
  Node->Next = NULL;

  // Case 1: No List, make the incoming node the Head
  if(Head == NULL){
    Head = Node;
    return;
  }

  // Case 2: Data on the New Node is less than the Head
  if(num <= Head->Data){
    Node->Next = Head;
    Head = Node;
    return;
  }

  // Case 3: Insert New Node at appropriate location
  Current = Head;
  Previous = NULL;
  
  while(Current != NULL && num >= Current->Data){
    Previous = Current;
    Current = Current->Next;
  }
  
  Previous->Next = Node;
  Node->Next = Current;
}

int SearchNode(int num){
  LISTNODE *Current;
  
  if(Head == NULL){
    return -1;
  } 
  
  Current = Head;
  while(Current != NULL){
    if(Current->Data == num){
      return 1; // Found
    }
    // Optimization: Since list is ordered, if current data > num, it's not there
    if(Current->Data > num){
      return -1;
    }
    Current = Current->Next;
  }
  return -1; // Not found
}

int DeleteNode(int num){
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

  // If we reached the end (NULL), the number wasn't found
  if(Current == NULL){
    return -1;
  }

  // Node found, unlink and free it
  Previous->Next = Current->Next;
  free(Current);
  return 1;
}