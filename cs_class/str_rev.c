/*
  Program to reverse a string using a Stack
  Pranav
  20 Feb, 2026
  str_rev.c
*/

#include <stdio.h>
#include <stdlib.h>
#define SIZE 100

typedef struct StackType {
    char A[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
void Push(char c);
char Pop();
int StackEmpty(); 

int main() {
    char str[SIZE];
    int i, len = 0;

    InitStack();

    printf("--- String Reverse ---\n");
    printf("Enter a string: ");
    scanf("%s", str);

    while (str[len] != '\0') {
        len++;
    }

    printf("\nOriginal string: %s\n", str);
    for (i = 0; i < len; i++) {
        Push(str[i]);
    }

    for (i = 0; i < len; i++) {
        str[i] = Pop();
    }

    str[len] = '\0'; 

    printf("Reversed string: %s\n", str);

    return 0;
}

//initializing the stack
void InitStack() {
    S.Top = -1;
}

//check if the stack is empty
int StackEmpty() {
    if (S.Top == -1) {
        return 1; 
    } else {
        return 0;
    }
}

//push function
void Push(char c) {
    if (S.Top == SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    S.Top++;
    S.A[S.Top] = c;
}

//pop function
char Pop() {
    char c;
    
    if (StackEmpty() == 1) {
        printf("Stack Underflow.\n");
        return '\0'; 
    }
    
    c = S.A[S.Top];
    S.Top--;
    return c;
}