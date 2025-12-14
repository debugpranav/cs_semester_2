/*
  Student Record Management System
  Pranav
  12-12-2025
  studentrecord.c
*/

#include<stdio.h>
#include<stdlib.h>
#include<memory.h>
#include<string.h>

typedef struct StudentData {
    char SID[20];
    char Name[50];
    float M1, M2, M3;
    float Total, Avg;
    int Result;
} STUDENT;

typedef struct ListType {
    STUDENT S;
    struct ListType *Next;
} LISTNODE;

LISTNODE *Head;

// Function Prototypes
void InitList();
void InsertListNode(STUDENT S);
void DisplayList(LISTNODE *Head);
void SearchStudent(char SID[]);
void PrintMksCard(STUDENT S);
void DeleteStudRecord(char SID[]);
void Menu(int *Choice);

int main(){
    int choice;
    char searchID[20];
    STUDENT S;

    InitList();

    while(1){
        Menu(&choice);
        
        switch(choice){
            case 1: // Add Student
                printf("\nEnter Register Number: ");
                scanf("%s", S.SID);
                printf("Enter Name: ");
                scanf("%s", S.Name);
                printf("Enter Marks (CS, MATH, STATS): ");
                scanf("%f %f %f", &S.M1, &S.M2, &S.M3);
                
                S.Total = S.M1 + S.M2 + S.M3;
                S.Avg = S.Total / 3.0;
                
                if(S.M1 < 35 || S.M2 < 35 || S.M3 < 35){
                    S.Result = -1; // Fail
                } else if(S.Avg >= 80){
                    S.Result = 1; // Distinction
                } else if(S.Avg >= 60){
                    S.Result = 2; // First Class
                } else {
                    S.Result = 3; // Pass
                }
                
                InsertListNode(S);
                break;

            case 2: // Delete Student
                printf("Enter Register Number to delete: ");
                scanf("%s", searchID);
                DeleteStudRecord(searchID);
                break;

            case 3: // Search Student
                printf("Enter Register Number to search: ");
                scanf("%s", searchID);
                SearchStudent(searchID);
                break;

            case 4: // Display Records
                DisplayList(Head);
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid Choice\n");
        }
    }
    return 0;
}

void InitList(){
    Head = NULL;
}

void Menu(int *Choice){
    printf("\n--- STUDENT RECORD MENU ---\n");
    printf("1. Add Student\n");
    printf("2. Delete Student\n");
    printf("3. Search Student\n");
    printf("4. Display Class Report\n");
    printf("5. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", Choice);
}

void InsertListNode(STUDENT S){
    LISTNODE *Node, *Current;
    
    Node = (LISTNODE *)malloc(sizeof(LISTNODE));
    Node->S = S;
    Node->Next = NULL;

    // Case 1: Empty List
    if(Head == NULL){
        Head = Node;
        return;
    }

    // Case 2: Insert at End
    Current = Head;
    while(Current->Next != NULL){
        Current = Current->Next;
    }
    Current->Next = Node;
}

void DeleteStudRecord(char SID[]){
    LISTNODE *Current, *Previous;

    if(Head == NULL){
        printf("List is empty.\n");
        return;
    }

    // Case 1: Delete Head
    if(strcmp(Head->S.SID, SID) == 0){
        Current = Head;
        Head = Head->Next;
        free(Current);
        printf("Student %s deleted.\n", SID);
        return;
    }

    // Case 2: Search and Delete
    Current = Head;
    Previous = NULL;
    while(Current != NULL && strcmp(Current->S.SID, SID) != 0){
        Previous = Current;
        Current = Current->Next;
    }

    if(Current == NULL){
        printf("Student not found.\n");
    } else {
        Previous->Next = Current->Next;
        free(Current);
        printf("Student %s deleted.\n", SID);
    }
}

void SearchStudent(char SID[]){
    LISTNODE *Current;
    
    if(Head == NULL){
        printf("List is empty.\n");
        return;
    }

    Current = Head;
    while(Current != NULL){
        if(strcmp(Current->S.SID, SID) == 0){
            PrintMksCard(Current->S);
            return;
        }
        Current = Current->Next;
    }
    printf("Student %s not found.\n", SID);
}

void PrintMksCard(STUDENT S){
    printf("\n\t\tMARKS CARD\n");
    printf("REGISTER NUMBER:\t%s\n", S.SID);
    printf("NAME:\t\t\t%s\n", S.Name);
    printf("CS:\t\t\t%.0f\n", S.M1);
    printf("MATH:\t\t\t%.0f\n", S.M2);
    printf("STATS:\t\t\t%.0f\n", S.M3);
    printf("TOTAL:\t\t\t%.0f\n", S.Total);
    printf("AVERAGE:\t\t%.2f\n", S.Avg);
    printf("RESULTS:\t\t");
    
    if(S.Result == 1){
        printf("Distinction\n");
    }else if(S.Result == 2){
        printf("First Class\n");
    }else if(S.Result == 3){
        printf("Pass\n");
    }else{
        printf("Fail\n");
    }
}

void DisplayList(LISTNODE *Head){
    LISTNODE *Current;
    
    if(Head == NULL){
        printf("List is empty.\n");
        return;
    }

    printf("\n\tST. JOSEPH'S UNIVERSITY\n");
    printf("\tCLASS REPORT\n");
    printf("\tBSc - Semester 1\n\n");
    
    printf("Register Number\tName\tCS\tMATH\tSTATS\tTOTAL\tAVERAGE\tRESULTS\n");
    printf("----------------------------------------------------------------------------\n");
    
    Current = Head;
    while(Current != NULL){
        printf("%s\t\t%s\t%.0f\t%.0f\t%.0f\t%.0f\t%.2f\t", 
            Current->S.SID, Current->S.Name, Current->S.M1, Current->S.M2, Current->S.M3, Current->S.Total, Current->S.Avg);
            
        if(Current->S.Result == 1){
            printf("Distinction\n");
        }else if(Current->S.Result == 2){
            printf("First Class\n");
        }else if(Current->S.Result == 3){
            printf("Pass\n");
        }else{
            printf("Fail\n");
        }
        
        Current = Current->Next;
    }
}