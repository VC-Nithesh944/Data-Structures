#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createnode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data= data;
    newnode->next = NULL;
    return newnode;
}

void push(int data,node** head){
    node* newnode = createnode(data);
    if (*head == NULL){
        *head = newnode;
        printf("\nelement pushed");
        return;
    }
    newnode->next = *head;
    *head = newnode;
    printf("\nelement pushed");
}

void pop(node** head){
    if(*head == NULL){
        printf("\nThe list is empty");
        return;
    }
    node* temp=*head;
    printf("The popped element is: %d",temp->data);
    *head = temp->next;
    free(temp);
}

void displays(node* head){
    if(head == NULL){
        printf("\nThe linekd list is empty");
        return;
    }
    node* temp= head;
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void enque(int data, node** front,node** rear){
    node* newnode = createnode(data);
    if(*front == NULL){
        *front= *rear = newnode;
        printf("\nElement equed");
        return;
    }
    (*rear)->next = newnode;
    *rear = newnode;
    printf("\nElement equed");
}

void deque(node** front, node** rear){
    if (*front == NULL){
        printf("\nThe list is Empty");
        return;
    }
    if(*front == *rear){
        node* temp = *front;
        printf("\nThe popped element is : %d",temp->data);
        *front = *rear = NULL;
        free(temp);
        return;
    }
    node* temp = *front;
    printf("The popped element is: %d",temp->data);
    *front = (*front)->next;
    free(temp);
    
}

void displayq(node* front, node* rear){
    if(front== NULL){
        printf("\nThe list is Empty");
        return;
    }
    while(front!=rear){
        printf("%d -> ",front->data);
        front = front->next;
    }
    printf("%d -> NULL",front->data);
}

int main(){
    node* head= NULL;
    node* front = NULL;
    node* rear = NULL;
    int choice , data;
    while(1){
        printf("\n1.push\n2.pop\n3.display stack\n4.enque\n5.deque\n6.display queue\n7.quit\n");
        printf("Enter a choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 :printf("\nEnter the data : ");
                    scanf("%d",&data);
                    push(data,&head);
            break;
            case 2: pop(&head);
            break;
            case 3:displays(head);
            break;
            case 4:printf("Enter the data: ");
                    scanf("%d",&data);
                    enque(data,&front,&rear);
            break;
            case 5:deque(&front,&rear);
            break;
            case 6:displayq(front,rear);
            break;
            case 7:return -1;
            break;
            default: printf("\nINvalid entry");
        }
    }
}
