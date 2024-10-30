#include <stdio.h>

typedef struct Node
{
    int data;
    struct Node *next;
}Node;


Node* createNode(int data){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return;
}

void insertAtFirst(int data,Node** head){
    Node* newNode = createNode(data);

    if (*head == NULL){
        *head = newNode;
        return;
    }

    newNode->next = *head;
    head = newNode;
    Display(*head);
}

void insertAtEnd(int data, Node** head){
    Node* newNode = createNode(data);
    if (*head == NULL){
        *head = newNode;
        return;
    }

    Node* temp = *head;

    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    Display(*head);
}

void insertAtSpecific(int data,int pos, Node** head){
    Node* newNode = createNode(data);

    if(pos == 1){
        insertAtFirst(data,&head);
        return;
    }

    Node* temp = *head;

    for (int i = 0; i<pos-1 && temp!= NULL;i++){
        temp = temp->next;
    }

    if (temp == NULL){
        printf("\nPosition is invalid\n");
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
    Display(*head);
}

void deleteAtFirst(Node** head){
    if(*head == NULL){
        printf("\nThe List is Empty\n");
        return;
    }

    Node* temp = *head;
    *head = temp->next;
    free(temp);
    Display(*head);
}

void deleteAtLast(Node** head){
    if(*head == NULL){
        printf("\nThe list is Empty\n");
        return;
    }
    Node* temp = *head;
    if(temp->next == NULL){
        free(*head);
        *head = NULL;
        return;
    }
    while(temp->next->next != NULL){
        temp = temp->next;
    }
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;
    Display(*head);
}

void deleteElement(int data, Node** head){
    if(*head == NULL){
        printf("\nThe List is Empty\n");
        return;
    }

    Node *temp = *head;
    if(temp->data == data){
        if(temp->next == NULL){
            free(*head);
            *head = NULL;
            Display(*head);
            return;
        }
        else{
            deleteAtFirst(&head);
            Display(*head);
            return;
        }
    }

    while(temp->next->data != data ){
         temp = temp->next;
    }
    if(temp->next->data != data){
        printf("\nElement is Not found\n");
        return;
    }
    Node* next = temp->next->next;
    free(temp->next);
    temp->next = next;

    Display(*head);
}

void Display(Node** head){
    if(*head == NULL){
        printf("\nThe List is Empty\n");
        return;
    }

    Node* temp = *head ;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){

    Node* head = NULL;
    while(1){
        printf("\n1.Insert at first\n2.Insert at Last\n3.Insert at position\n4.Delete at First\n5.Delete At last\n6.Delete a element\n7.Quit\n8.Create List\n9.Display\n");
        printf("Enter Your choice: ");
        int choice ;
        scanf("%d",&choice);
        int data;
        int pos;
        switch(choice){
            case 1: printf("\nEnter the element:");
                    scanf("%d",&data);
                    insertAtFirst(data,&head);
                    break;
            case 8: printf("\nEnter the element:");
                    scanf("%d",&data);
                    insertAtEnd(data,&head);
                    break;
            case 2:printf("\nEnter the element:");
                    scanf("%d",&data);
                    insertAtEnd(data,&head);
                    break;
            case 3: printf("\nEnter the element:");
                    scanf("%d",&data);
                    printf("\nEnter the position: ");
                    scanf("%d",&pos);
                    insertAtSpecific(data,pos,&head);
                    break;
            case 4: deleteAtFirst(&head);
                    break;
            case 5:deleteAtLast(&head);
                    break;
            case 6: printf("Enter the element: ");
                    scanf("%d",&data);
                    deleteElement(data,&head);
                    break;
            case 9: Display(&head);
            break;
            case 7: return;
            break;
            default: printf("\nINvalid Entry");

        }
    }
}
