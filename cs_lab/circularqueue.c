/*
  Menu program to show the working of a Circular Queue (Linked List)
  Pranav
  13-12-2025
  circularqueue.c
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
    printf("\n--- Circular Queue Menu ---\n");
    printf("1. Enqueue (Insert)\n");
    printf("2. Dequeue (Delete)\n");
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
          printf("Dequeued Value: %d\n", deletedData);
        } else {
          printf("Queue is empty, cannot Dequeue.\n");
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
  
  // Allocate memory
  Node = (QUEUENODE *)malloc(sizeof(QUEUENODE));
  Node->Data = num;
  Node->Next = NULL;

  // Case 1: Empty Queue
  if(Front == NULL){
    Front = Node;
    Rear = Node;
    Rear->Next = Front; // Point back to Front to form a circle
  }
  else {
    // Case 2: Add to Rear
    Rear->Next = Node;
    Rear = Node;
    Rear->Next = Front; // Maintain the circular link
  }
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
  
  // Case 2: Only one node in the queue
  if(Front == Rear){
    Front = NULL;
    Rear = NULL;
    free(Current);
  }
  else {
    // Case 3: Multiple nodes
    Front = Front->Next;
    Rear->Next = Front; // Update Rear to point to the new Front
    free(Current);
  }
  
  return num;
}

void DisplayQueue(){
  QUEUENODE *Current;
  
  if(Front == NULL){
    printf("Queue is empty\n");
    return;
  }
  
  Current = Front;
  printf("FRONT -> ");
  
  // Use do-while loop to traverse the circular list once
  do {
    printf("%d -> ", Current->Data);
    Current = Current->Next;
  } while(Current != Front);
  
  printf("(Back to FRONT)\n");
}