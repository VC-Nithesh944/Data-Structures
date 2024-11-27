#include <stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node *left, *right;
}Node;

Node* createnode(int data){
    Node* newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node* insertnode(Node* root, int data){
    if (root == NULL){
        return createnode(data);
    }
    else if (data < root->data)
        root->left = insertnode(root->left, data);
    else if (data>root->data)
        root->right = insertnode(root->right, data);
    return root;
}

void preorder(Node* root){
    if (root != NULL){
        printf("%d -> ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(Node* root){
    if (root != NULL){
        inorder(root->left);
        printf("%d -> ",root->data);
        inorder(root->right);
    }
}

void postorder(Node* root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d -> ",root->data);
    }
}

int main(){
    Node* root = NULL;
    int data, choice;
    while (1){
        printf("\nTREES OPERATIONS \n");
        printf("1.Insert a node\n2.Preorder traversal\n3.inorder traversal\n4.postorder traversa\n5.Exit");
        printf("\nENter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1: printf("\nEnter the data:");
                scanf("%d",&data);
                root = insertnode(root,data);
            break;
            case 2:
                    preorder(root);
            break;
            case 3:inorder(root);
            break;
            case 4:postorder(root);
            break;
            case 5 : return;
            break;
        }
    }
}
