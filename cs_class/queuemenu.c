/*
  Menu driven program for Queue (EnQueue and DeQueue)
  Pranav
  11-12-2025
  queuemenu.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef struct QueueType {
  int Data;
  struct QueueType *Next;
} QUEUENODE;

QUEUENODE *Front, *Rear;

//prototype
void InitQueue();
void EnQueue(int num);
int DeQueue();
void DisplayQueue();

int main (){
  int choice, num, deletedData;

  InitQueue();

  while(1){
    printf("\n--- Queue Menu (FIFO) ---\n");
    printf("1. Insert (EnQueue)\n");
    printf("2. Delete (DeQueue)\n");
    printf("3. Display Queue\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter the number to insert: ");
        scanf("%d", &num);
        EnQueue(num);
        break;
        
      case 2:
        deletedData = DeQueue();
        if(deletedData != -1){
          printf("Deleted Value: %d\n", deletedData);
        } else {
          printf("Queue is empty, cannot delete.\n");
        }
        break;
        
      case 3:
        DisplayQueue();
        break;
        
      case 4:
        exit(0);
        
      default:
        printf("Invalid choice\n");
    }
  }
  return 0;
}

void InitQueue(){
  Front = NULL;
  Rear = NULL;
}

void EnQueue(int num){
  QUEUENODE *Node;
  
  //assigning memory and assigning values
  Node = (QUEUENODE *)malloc(sizeof(QUEUENODE));
  Node->Data = num;
  Node->Next = NULL;

  //case 1: no queue, make the incoming node the front and rear
  if(Front == NULL){
    Front = Node;
    Rear = Node;
    return;
  }

  //case 2: attach incoming node to the rear of the queue and make the new node to rear
  Rear->Next = Node;
  Rear = Node;
}

int DeQueue(){
  QUEUENODE *Node;
  int num;
  
  // Case 1: Queue is empty
  if(Front == NULL){
    printf ("Queue is Empty.\n");
    return -1;
  }
  
  // Case 2: Only one node in Queue
  if(Front == Rear){
    num = Front -> Data;;
    Front = Rear = NULL;
    return num;
  }
  Node = Front;
  num = Node -> Data;
  Front = Node -> Next;
  free(Node);
  return num;
} 

void DisplayQueue(){
  QUEUENODE *Current;
  
  if(Front == NULL){
    printf("Queue is empty\n");
    return;
  }
  
  Current = Front;
  while(Current != NULL){
    printf("%d -> ", Current->Data);
    Current = Current->Next;
  }
  printf("NULL\n");
}