/*
  Program to implement Queue using Linked List (InitQueue and EnQueue)
  Pranav
  9-12-2025
  queuelist.c
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
void DisplayQueue();

int main (){
  int num, n, i;

  InitQueue();

  printf("Program to enter elements in Queue (FIFO)\n");
  printf("Enter number of elements to be inserted: ");
  scanf("%d", &n);
  
  for(i=0; i<n; i++){
    printf("Enter the number: ");
    scanf("%d", &num);
    EnQueue(num);
  }
  
  DisplayQueue();
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

void DisplayQueue(){
  QUEUENODE *Current;
  
  if(Front == NULL){
    printf("Queue is empty\n");
    return;
  }
  
  printf("\nQueue Contents:\n");
  Current = Front;
  while(Current != NULL){
    printf("%d -> ", Current->Data);
    Current = Current->Next;
  }
  printf("NULL\n");
}