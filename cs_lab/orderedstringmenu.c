/*
  Menu driven program for Ordered Linked List with Strings
  Pranav
  8-12-2025
  orderedstringmenu.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef struct ListType {
  char Data[50];
  struct ListType *Next;
} LISTNODE;

LISTNODE *Head;

//prototype
void InitList();
void InsertStringNode(char *str);
void DisplayList(LISTNODE *head);
int SearchStringNode(char *str);
int DeleteStringNode(char *str);

int main (){
  int choice, status;
  char str[50];

  InitList();

  while(1){
    printf("\n--- Ordered String Linked List Menu ---\n");
    printf("1. Insert a string\n");
    printf("2. Display the list\n");
    printf("3. Search for a string\n");
    printf("4. Delete a string\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter the string to insert: ");
        scanf("%s", str);
        InsertStringNode(str);
        break;
        
      case 2:
        DisplayList(Head);
        break;
        
      case 3:
        printf("Enter the string to search: ");
        scanf("%s", str);
        status = SearchStringNode(str);
        if(status == 1)
          printf("String '%s' found in the list.\n", str);
        else
          printf("String '%s' not found.\n", str);
        break;
        
      case 4:
        printf("Enter the string to delete: ");
        scanf("%s", str);
        status = DeleteStringNode(str);
        if(status == 1)
          printf("String '%s' deleted successfully.\n", str);
        else
          printf("String '%s' not found or List is empty.\n", str);
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
    printf("%s -> ", Current->Data);
    Current = Current->Next;
  }
  printf("NULL\n");
}

void InsertStringNode(char *str){
  LISTNODE *Current, *Previous, *Node;
  
  Node = (LISTNODE *)malloc(sizeof(LISTNODE));
  strcpy(Node->Data, str);
  Node->Next = NULL;

  // Case 1: No List, make the incoming node the Head
  if(Head == NULL){
    Head = Node;
    return;
  }

  // Case 2: New String is alphabetically smaller than Head
  // strcmp returns < 0 if str is "less than" Head->Data
  if(strcmp(str, Head->Data) <= 0){
    Node->Next = Head;
    Head = Node;
    return;
  }

  // Case 3: Insert New Node at appropriate location
  Current = Head;
  Previous = NULL;
  
  // Keep traversing while current string is "smaller" than input string
  while(Current != NULL && strcmp(str, Current->Data) >= 0){
    Previous = Current;
    Current = Current->Next;
  }
  
  Previous->Next = Node;
  Node->Next = Current;
}

int SearchStringNode(char *str){
  LISTNODE *Current;
  
  if(Head == NULL){
    return -1;
  }
  
  Current = Head;
  while(Current != NULL){
    if(strcmp(Current->Data, str) == 0){
      return 1; // Found
    }
    // Optimization: Since list is ordered, if current data is "greater", stop
    if(strcmp(Current->Data, str) > 0){
      return -1;
    }
    Current = Current->Next;
  }
  return -1; // Not found
}

int DeleteStringNode(char *str){
  LISTNODE *Current, *Previous;

  // Case 1: List is empty
  if(Head == NULL){
    return -1;
  }

  // Case 2: The node to delete is the Head
  if(strcmp(Head->Data, str) == 0){
    Current = Head;
    Head = Head->Next; 
    free(Current);
    return 1;
  }

  // Case 3: Traverse to find the node
  Current = Head;
  Previous = NULL;
  
  while(Current != NULL && strcmp(Current->Data, str) != 0){
    Previous = Current;
    Current = Current->Next;
  }

  // If we reached the end (NULL), the string wasn't found
  if(Current == NULL){
    return -1;
  }

  // Node found, unlink and free it
  Previous->Next = Current->Next;
  free(Current);
  return 1;
}