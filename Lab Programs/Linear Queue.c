#include<stdio.h>

void Enque(int data, int* queue, int n, int *front, int *rear){           //* queue or queue[] to pass entire array
    if (*rear == n - 1){
        printf("Queue Overflow!!\n");
        return;
    }
    if (*front == -1 && *rear == -1){
        *front = *rear = 0;
        queue[*rear] = data;
    }
    else{
        *rear = *rear + 1;
        queue[*rear] = data;
    }
    printf("Element Successfully Entered!!\n");
}

int Deque(int *queue, int* front , int* rear){
    if (*front == -1 || *front > *rear){
        printf("Queue UnderFlow!!\n");
        exit(1);
    }
    int value = queue[*front];
    *front = *front + 1;
    return value;
}

void Display(int *queue,int *front, int* rear){
    if(*front == -1 || *front > *rear){
        printf("Queue is Empty!!\n");
        return;
    }
    printf("The element of the array are : ");
    for (int i = *front; i<= *rear; i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}

int Rear(int * queue, int *rear){
    if (*rear == -1){
        printf("The Queue is Empty!!\n");
        exit(1);
    }
    return queue[*rear];
}

int Front(int* queue, int *front){
    if(*front == -1){
        printf("The Queue is Empty!!\n");
        exit(1);
    }
    return queue[*front];
}

int main(){
    printf("Enter the size of Queue you want: ");
    int n;
    scanf("%d",&n);
    int queue[n], front = -1, rear = -1;
    while(1){
    printf("\n1.Enque an Element \n2.Deque an Element \n3.Display the Queue\n4.Display the Rear Element \n5.Display the Front Element.\n6.Quit\n");
    printf("Enter your choice:");
    int choice;
    scanf("%d",&choice);
    switch(choice){
        case 1: printf("Enter the element you want to Enque: ");
                int data;
                scanf("%d",&data);
                Enque(data,queue,n,&front,&rear);
                break;
        case 2: printf("\nThe element Dequed is : %d\n",Deque(queue,&front,&rear));
                break;
        case 3: Display(queue,&front,&rear);
                break;
        case 4: printf("\nThe Rear Element of the Queue is : %d\n",Rear(queue,&rear));
                break;
        case 5: printf("\nThe Front Element of the Queue is: %d\n",Front(queue,&front));
                break;
        case 6: printf("\nSuccessfully Exited\n");
                exit(1);
                break;
        default: printf("\nInvalid Entry!!\n");
    }
    }
}
