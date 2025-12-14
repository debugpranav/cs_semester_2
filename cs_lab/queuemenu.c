/*
  Menu program to show the working of a Queue (Enqueue, Dequeue, Exit)
  Pranav
  13-12-2025
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
    printf("\n--- Queue Operations Menu ---\n");
    printf("1. Enqueue (Insert)\n");
    printf("2. Dequeue (Delete)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch(choice){
      case 1:
        printf("Enter the number to Enqueue: ");
        scanf("%d", &num);
        EnQueue(num);
        printf("Current Queue: ");
        DisplayQueue();
        break;
        
      case 2:
        deletedData = DeQueue();
        if(deletedData != -1){
          printf("Dequeued Value: %d\n", deletedData);
        } else {
          printf("Queue is empty, cannot Dequeue.\n");
        }
        printf("Current Queue: ");
        DisplayQueue();
        break;
        
      case 3:
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
  
  // Allocate memory and assign values
  Node = (QUEUENODE *)malloc(sizeof(QUEUENODE));
  Node->Data = num;
  Node->Next = NULL;

  // Case 1: No queue, make the incoming node the Front and Rear
  if(Front == NULL){
    Front = Node;
    Rear = Node;
    return;
  }

  // Case 2: Attach incoming node to the rear and update Rear pointer
  Rear->Next = Node;
  Rear = Node;
}

int DeQueue(){
  QUEUENODE *Current;
  int num;
  
  // Case 1: Queue is empty
  if(Front == NULL){
    return -1;
  }
  
  Current = Front;
  num = Current->Data;
  
  // Case 2: Only one node in Queue (Front and Rear are same)
  if(Front == Rear){
    Front = NULL;
    Rear = NULL;
  }
  else {
    // Case 3: More than one node, move Front forward
    Front = Front->Next;
  }
  
  free(Current);
  return num;
}

void DisplayQueue(){
  QUEUENODE *Current;
  
  if(Front == NULL){
    printf("Empty\n");
    return;
  }
  
  Current = Front;
  while(Current != NULL){
    printf("%d -> ", Current->Data);
    Current = Current->Next;
  }
  printf("NULL\n");
}