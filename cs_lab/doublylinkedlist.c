/*
  Menu driven program to show the working of a Doubly Linked List
  Pranav
  5-1-2026
  doublylinkedlist.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct DbLnkType {
  int Data;
  struct DbLnkType *Next;
  struct DbLnkType *Previous;
} DBLLNKNODE;

DBLLNKNODE *Head;

//prototype
void InitDblList();
void InsertDblNode(int num);
void DisplayForward();
void DisplayBackward();
int DeleteDblNode(int num);

int main (){
  int choice, num, status;

  InitDblList();

  while(1){
    printf("\n--- Doubly Linked List Menu ---\n");
    printf("1. Enter a number\n");
    printf("2. Display Forward & Backward\n");
    printf("3. Delete a number\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter the number to insert: ");
        scanf("%d", &num);
        InsertDblNode(num);
        break;
        
      case 2:
        printf("\nForward Display:\n");
        DisplayForward();
        printf("Backward Display:\n");
        DisplayBackward();
        break;
        
      case 3:
        printf("Enter the number to delete: ");
        scanf("%d", &num);
        status = DeleteDblNode(num);
        if(status == 1)
          printf("Number %d deleted successfully.\n", num);
        else
          printf("Operation Failed: Number %d not found or List is empty.\n", num);
        break;
        
      case 4:
        exit(0);
        
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

void InitDblList(){
  Head = NULL;
}

void InsertDblNode(int num){
  DBLLNKNODE *Current, *Node, *Previous;
  
  // Allocate memory
  Node = (DBLLNKNODE *)malloc(sizeof(DBLLNKNODE));
  Node->Data = num;
  Node->Next = NULL;
  Node->Previous = NULL;

  // Case 1: No List, make the incoming node the Head
  if(Head == NULL){
    Head = Node;
    return;
  }

  // Case 2: Insert at Head (Data is smaller than Head)
  if(num <= Head->Data){
    Node->Next = Head;
    Head->Previous = Node;
    Head = Node;
    return;
  }

  // Case 3: Traverse and Insert (Middle or End)
  Current = Head;
  Previous = NULL;

  while(Current != NULL && num >= Current->Data){
    Previous = Current;
    Current = Current->Next;
  }
  Previous->Next = Node;
  Node->Previous = Previous;
  Node->Next = Current;
  
  if(Current != NULL){
    Current->Previous = Node;
  }
}

void DisplayForward(){
  DBLLNKNODE *Current;
  if(Head == NULL){
    printf("List is empty\n");
    return;
  }
  Current = Head;
  printf("HEAD -> ");
  while(Current != NULL){
    printf("%d -> ", Current->Data);
    Current = Current->Next;
  }
  printf("NULL\n");
}

void DisplayBackward(){
  DBLLNKNODE *Current;
  if(Head == NULL){
    printf("List is empty\n");
    return;
  }
  
  // Step 1: Traverse to the last node
  Current = Head;
  while(Current->Next != NULL){
    Current = Current->Next;
  }
  
  // Step 2: Traverse backwards using Previous pointer
  printf("TAIL -> ");
  while(Current != NULL){
    printf("%d -> ", Current->Data);
    Current = Current->Previous;
  }
  printf("NULL\n");
}

int DeleteDblNode(int num){
  DBLLNKNODE *Current;

  if(Head == NULL){
    return -1;
  }

  // Case 1: Deleting the Head node
  if(Head->Data == num){
    Current = Head;
    Head = Head->Next;
    
    // If list is not empty after deletion, update new Head's Previous
    if(Head != NULL){
      Head->Previous = NULL; 
    }
    
    free(Current);
    return 1;
  }

  // Case 2: Traverse to find the node
  Current = Head;
  while(Current != NULL && Current->Data != num){
    Current = Current->Next;
  }

  // Node not found
  if(Current == NULL){
    return -1;
  }

  // Case 3: Node found (Middle or End)
  // Unlink from the previous node
  if(Current->Previous != NULL){
    Current->Previous->Next = Current->Next;
  }
  
  // Unlink from the next node (if it exists)
  if(Current->Next != NULL){
    Current->Next->Previous = Current->Previous;
  }

  free(Current);
  return 1;
}