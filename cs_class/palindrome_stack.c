/*
  Program to check if a string is a palindrome using a Stack
  Pranav
  20 Feb, 2026
  palindrome_stack.c
*/

#include <stdio.h>
#include <string.h>
#define SIZE 100

typedef struct StackType {
    char A[SIZE];
    int Top;
} STACK;

STACK S;

void InitStack();
void Push(char c);
char Pop();

int main() {
    char str[SIZE];
    int i, len, Palindrome = 1;

    InitStack();

    printf("--- Palindrome Check ---\n");
    printf("Enter a string: ");
    scanf("%s", str);

    len = strlen(str);

    for (i = 0; i < len; i++) {
        Push(str[i]);
    }

    for (i = 0; i < len; i++) {
        if (str[i] != Pop()) {
            Palindrome = 0;
            break;
        }
    }

    if (Palindrome == 1) {
        printf("\n\"%s\" is a Palindrome!\n", str);
    } else {
        printf("\n\"%s\" is NOT a Palindrome.\n", str);
    }

    return 0;
}

void InitStack() {
    S.Top = -1;
}

void Push(char c) {
    if (S.Top == SIZE - 1) {
        printf("Stack Overflow.\n");
        return;
    }
    S.Top++;
    S.A[S.Top] = c;
}

char Pop() {
    char c;
    if (S.Top == -1) {
        printf("Stack Underflow.\n");
        return '\0';
    }
    c = S.A[S.Top];
    S.Top--;
    return c;
}