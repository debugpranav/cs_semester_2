/*
  Program to check if a string is a palindrome using a Stack
  Pranav
  pal_stack.c
  23 Feb, 2026
*/

#include <stdio.h>
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
    int i, len = 0, isPalindrome = 1;

    InitStack();

    printf("--- Palindrome Checker ---\n");
    printf("Enter a string: ");
    scanf("%s", str);

    while (str[len] != '\0') {
        len++;
    }

    for (i = 0; i < len; i++) {
        Push(str[i]);
    }

    for (i = 0; i < len; i++) {
        if (str[i] != Pop()) {
            isPalindrome = 0;
            break;
        }
    }

    if (isPalindrome == 1) {
        printf("\n\"%s\" is a Palindrome!\n", str);
    } else {
        printf("\n\"%s\" is NOT a Palindrome.\n", str);
    }

    return 0;
}

void InitStack() {
    S.Top = -1;
}

int StackEmpty() {
    if (S.Top == -1) {
        return 1; 
    } else {
        return 0;
    }
}

void Push(char ch) {
    if (S.Top == SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    S.Top++;
    S.A[S.Top] = ch;
}

char Pop() {
    char ch;
    
    if (StackEmpty() == 1) {
        printf("Stack Underflow.\n");
        return '\0'; 
    }
    
    ch = S.A[S.Top];
    S.Top--;
    return ch;
}