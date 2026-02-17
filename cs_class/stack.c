#include <stdio.h>

#define SIZE 10

typedef struct StackType {
    int A[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
void Push(int num);
int Pop();

int main(){
    int deletedNum;

    InitStack();
    
    Push(5);
    Push(10);
    Push(15);
    
    deletedNum = Pop();
    
    if (deletedNum != -1) {
        printf("Popped number is: %d\n", deletedNum);
    }
    
    return 0;
}

void InitStack(){
    S.Top = -1; 
}

void Push(int num) {
    if (S.Top == SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    S.Top++;
    S.A[S.Top] = num;
}

int Pop(){
    int num;

    if (S.Top == -1) {
        printf("Stack Underflow. The stack is empty.\n");
        return -1;
    }

    num = S.A[S.Top];
    S.Top--;

    return num;
}