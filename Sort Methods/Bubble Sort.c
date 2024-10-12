// Bubble sort has the Worst, Average case Time Complexity of O(n^2)
//But has the Best case Time Complexity of O(n) when all elements are in ascending order.
//Some Alteration to the code needs to made in order to achieve O(n).
#include <stdio.h>

void bubble_sort(int *arr, int n){
    int swaped = 0;                          //This the alteration factor to get O(n) -> go to line 17
    for(int i = 0; i<n-1;i++){               
        for (int j = 0; j < n-1;j++){        
            if (arr[j] > arr[j+1             //this method compares whether the element is greater than its adjacent element
                int temp = arr[j];           // if yes , they both get swaped and the comparision continues
                arr[j] = arr[j+1];           //By the end of first iteration its for sure that the last element of the array would be largest
                arr[j+1] = temp;
                swaped = 1;
            }
        }
        if (!swaped){                        //During the first iteration, if swaping doesn't takes place then the array is already sorted.
            break;                           // I want you to think about it
        }
    }
}

void Print(int arr[], int n){
    for (int i = 0; i< n; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int main() {
    int n ; 
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i = 0; i < n; i++){
        printf("Enter the %d element: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("The elements of array before bubble sorting: ");
    Print(arr,n);
    bubble_sort(arr,n);
    printf("The elements of array after bubble sorting; ");
    Print(arr,n);
}
