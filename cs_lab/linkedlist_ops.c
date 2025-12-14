/*
  Menu driven program for Singly Linked List Operations
  (Max, Count, Delete Specific, Delete Last)
  Pranav
  14-12-2025
  linkedlist_ops.c
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
int FindMax();
int CountNodes();
int DeleteNode(int num);
int DeleteLastNode();

int main (){
  int choice, num, status, result;

  InitList();

  while(1){
    printf("\n--- Linked List Operations Menu ---\n");
    printf("1. Insert a number (Append)\n");
    printf("2. Display List\n");
    printf("3. Find Maximum Value\n");
    printf("4. Count Total Nodes\n");
    printf("5. Delete a specific number\n");
    printf("6. Delete the Last Node\n");
    printf("7. Exit\n");
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
        result = FindMax();
        if(result != -1){
          printf("Maximum Value in the list is: %d\n", result);
        } else {
          printf("List is empty.\n");
        }
        break;
        
      case 4:
        result = CountNodes();
        printf("Total number of nodes: %d\n", result);
        break;
        
      case 5:
        printf("Enter the number to delete: ");
        scanf("%d", &num);
        status = DeleteNode(num);
        if(status == 1){
          printf("Number %d deleted successfully.\n", num);
        } else {
          printf("Number %d not found or List is empty.\n", num);
        }
        break;

      case 6:
        status = DeleteLastNode();
        if(status == 1){
          printf("Last node deleted successfully.\n");
        } else {
          printf("List is empty.\n");
        }
        break;
        
      case 7:
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

int FindMax(){
  LISTNODE *Current;
  int max;

  if(Head == NULL){
    return -1;
  }

  Current = Head;
  max = Head->Data; // Initialize max with the first element

  while(Current != NULL){
    if(Current->Data > max){
      max = Current->Data;
    }
    Current = Current->Next;
  }
  return max;
}

int CountNodes(){
  LISTNODE *Current;
  int count = 0;

  Current = Head;
  while(Current != NULL){
    count++;
    Current = Current->Next;
  }
  return count;
}

int DeleteNode(int num){
  LISTNODE *Current, *Previous;

  if(Head == NULL) return -1;

  // Case 1: Delete Head
  if(Head->Data == num){
    Current = Head;
    Head = Head->Next;
    free(Current);
    return 1;
  }

  // Case 2: Traverse to find
  Current = Head;
  Previous = NULL;
  
  while(Current != NULL && Current->Data != num){
    Previous = Current;
    Current = Current->Next;
  }

  if(Current == NULL){
    return -1;
  }

  // Case 3: Delete
  Previous->Next = Current->Next;
  free(Current);
  return 1;
}

int DeleteLastNode(){
  LISTNODE *Current, *Previous;

  if(Head == NULL) return -1;

  // Case 1: Only one node exists
  if(Head->Next == NULL){
    free(Head);
    Head = NULL;
    return 1;
  }

  // Case 2: Traverse to the last node
  Current = Head;
  Previous = NULL;

  while(Current->Next != NULL){
    Previous = Current;
    Current = Current->Next;
  }

  // Current is now the last node, Previous is the second to last
  Previous->Next = NULL;
  free(Current);
  return 1;
}