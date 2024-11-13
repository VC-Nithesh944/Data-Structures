#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next;
}node;

void enqueue(int val,node** front, node** rear)
{
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    if (*front == NULL && *rear == NULL)
        *front = *rear = newNode;
    else
    {
        // add newnode in rear->next
        (*rear)->next = newNode;
        // make the new node as the rear node
        *rear = newNode;
    }
}
void dequeue(node** front, node** rear)
{
    // used to free the first node after dequeue
    struct node *temp;
    if (*front == NULL)
        printf("Queue is Empty. Unable to perform dequeue\n");
    else
    {

        temp = *front;
        *front = (*front)->next;
        // if front == NULL, set rear = NULL
        if (*front == NULL)
            *rear = NULL;
        // free the first node
        free(temp);
    }
}
void printList(node* front)
{
    struct node *temp = front;
    while (temp)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    node* front = NULL;
    node* rear = NULL;
    int choice;
    while (1){
        printf("\n1.Enque\n2.Deque\n3.printlist\n4.quit");
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : printf("ENter the element you want to enqueue: ");
                    int data;
                    scanf("%d",&data);
                    enqueue(data,&front, &rear);
                    break;
            case 2 : dequeue(&front, &rear);
            break;
            case 3: printList(front);
            break;
            case 4 : return -1;
            break;
            default : printf("INvalid entry");
        }
    }
    
}
