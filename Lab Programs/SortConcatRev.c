#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* createnode(int data){
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insertatbeginning(int data, node** head){
    node* newnode = createnode(data);
    if (*head == NULL){
        *head = newnode;
        return;
    }
    newnode->next = *head;
    *head = newnode;
}

node* sort(node* head1){
    node* current, *temp;
    current = head1;
    int tempvar;
    while(current!=NULL){
        temp = head1;
        while(temp->next !=NULL){
            if (temp->data > temp->next->data){
            tempvar = temp->data;
            temp->data = temp->next->data;
            temp->next->data = tempvar;
            }
            temp= temp->next;
        }
        current= current->next;
    }
    return head1;
}

node* concat(node* head1,node* head2){
    node* temp = head1;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = head2;
    return head1;
}

node* reverse(node* head){
    if (head == NULL){
        printf("\nThe ll is empty");
        return;
    }
    node* prev = NULL, *temp = head, *next;
    while(temp!= NULL){
        next = temp->next;
        temp->next = prev;
        prev = temp;
        temp = next;
    }
    head = prev;
    return head;
}

void display(node* head){
    if(head == NULL){
        printf(
            "\nThe list is empty"
        );
    }
    node* temp = head;
    while(temp != NULL){
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    node* list1 = NULL;
    node* list2 = NULL;

    int choice , data;
    while(1){
        printf("\n1.inserteatB\n2.sort list1\n3.sort list2\n4.concat\n5.reverse list1\n6.reverse list2\n7.quit\n");
        printf("Enter the choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:printf("\nEnter the data : ");
                        scanf("%d",&data);
                        printf("\n1.Enter to list1\n2.Enter to list2\n");
                        printf("Enter your choice : ");
                        scanf("%d",&choice);
                        if(choice == 1){
                            insertatbeginning(data,&list1);
                            display(list1);
                    }
                    else{
                        insertatbeginning(data,&list2);
                        display(list2);
                    }
            break;
            case 2:list1 = sort(list1);
                    display(list1);
            break;
            case 3:list2 = sort(list2);
            display(list2);
            break;
            case 4:node* list1 = concat(list1,list2);
            printf("\nThe concatenated list1 is : ");
                    display(list1);
            break;
            case 5:list1 = reverse(list1);
                display(list1);
            break;
            case 6:list2 = reverse(list2);
            display(list2);
            break;
            case 7:return -1;
            break;
            default: printf("\nINvalid entry");
        }
    }
}
