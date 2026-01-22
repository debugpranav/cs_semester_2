/* Program to show the working of a Binary Search Tree with Menu
   Pranav
   22 Jan, 2026
   bst_menu.c */
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeType{
    int num;
    struct TreeType *left;
    struct TreeType *right;
} TREENODE;

TREENODE *Root;

// Function declarations
void InitTree();
void InsertTreeNode(int num);
void Preorder(TREENODE *Root);
void Inorder(TREENODE *Root);
void Postorder(TREENODE *Root);
void DisplayLeafNodes(TREENODE *Root);
int SearchNode(TREENODE *Root, int num);

int main(){
    int choice, num;
    
    InitTree();  // Initialize the tree
    
    while(1){
        printf("\n========== BINARY SEARCH TREE MENU ==========\n");
        printf("1) Insert a number\n");
        printf("2) PREORDER traversal\n");
        printf("3) INORDER traversal\n");
        printf("4) POSTORDER traversal\n");
        printf("5) Display only LEAF NODES\n");
        printf("6) Search for a given data item\n");
        printf("7) EXIT\n");
        printf("=============================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice){
            case 1:
                printf("Enter the number to insert: ");
                scanf("%d", &num);
                InsertTreeNode(num);
                printf("Number %d inserted successfully!\n", num);
                break;
                
            case 2:
                if(Root == NULL){
                    printf("Tree is empty!\n");
                }else{
                    printf("PREORDER Traversal: ");
                    Preorder(Root);
                    printf("\n");
                }
                break;
                
            case 3:
                if(Root == NULL){
                    printf("Tree is empty!\n");
                }else{
                    printf("INORDER Traversal: ");
                    Inorder(Root);
                    printf("\n");
                }
                break;
                
            case 4:
                if(Root == NULL){
                    printf("Tree is empty!\n");
                }else{
                    printf("POSTORDER Traversal: ");
                    Postorder(Root);
                    printf("\n");
                }
                break;
                
            case 5:
                if(Root == NULL){
                    printf("Tree is empty!\n");
                }else{
                    printf("LEAF NODES: ");
                    DisplayLeafNodes(Root);
                    printf("\n");
                }
                break;
                
            case 6:
                if(Root == NULL){
                    printf("Tree is empty!\n");
                }else{
                    printf("Enter the number to search: ");
                    scanf("%d", &num);
                    if(SearchNode(Root, num)){
                        printf("Number %d FOUND in the tree!\n", num);
                    }else{
                        printf("Number %d NOT FOUND in the tree!\n", num);
                    }
                }
                break;
                
            case 7:
                printf("Exiting program. Goodbye!\n");
                exit(0);
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}

// Function definitions
void InitTree(){
    Root = NULL;
}

void InsertTreeNode(int num){
    TREENODE *Current, *Node, *Previous;
    Node = (TREENODE*)malloc(sizeof(TREENODE));
    Node->num = num;
    Node->left = NULL;
    Node->right = NULL;
    
    if (Root == NULL){
        Root = Node;
        return;
    }
    
    Current = Root;
    while(Current != NULL){
        Previous = Current;
        if(num < Current->num){
            Current = Current->left;
        }else{
            Current = Current->right;
        }
    }
    
    if(num < Previous->num){
        Previous->left = Node;
    }else{
        Previous->right = Node;
    }
}

void Preorder(TREENODE *Root){
    if(Root != NULL){
        printf("%d ", Root->num);
        Preorder(Root->left);
        Preorder(Root->right);
    }
}

void Inorder(TREENODE *Root){
    if(Root != NULL){
        Inorder(Root->left);
        printf("%d ", Root->num);
        Inorder(Root->right);
    }
}

void Postorder(TREENODE *Root){
    if(Root != NULL){
        Postorder(Root->left);
        Postorder(Root->right);
        printf("%d ", Root->num);
    }
}

void DisplayLeafNodes(TREENODE *Root){
    if(Root != NULL){
        if(Root->left == NULL && Root->right == NULL){
            printf("%d ", Root->num);
        }
        DisplayLeafNodes(Root->left);
        DisplayLeafNodes(Root->right);
    }
}

int SearchNode(TREENODE *Root, int num){
    if(Root == NULL){
        return 0;
    }
    if(Root->num == num){
        return 1;
    }
    if(num < Root->num){
        return SearchNode(Root->left, num);
    }else{
        return SearchNode(Root->right, num);
    }
}