/* 
   Program to find the factorial of a given number
   Pranav
   23 Feb, 2026
   factorial_stack.c
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

typedef struct StackType {
    int A[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
void Push(int num);
int Pop();

int main() {
    int i, N, num, Fact;

    InitStack();

    printf("Enter the Number: ");
    scanf("%d", &N);

    i = 2;
    Push(1);
    
    while(i <= N) {
        num = Pop();
        Push(num * i);
        i++;
    }
    
    Fact = Pop();

    printf("Factorial of %d is: %d\n", N, Fact);

    return 0;
}

void InitStack() {
    S.Top = -1;
}

void Push(int num) {
    if(S.Top == SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    S.Top++;
    S.A[S.Top] = num;
}

int Pop() {
    int num;
    if(S.Top == -1) {
        printf("Stack Underflow.\n");
        return -1;
    }
    num = S.A[S.Top];
    S.Top--;
    return num;
}