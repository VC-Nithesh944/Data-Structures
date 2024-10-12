//Selection sorting has Worst, Average and Best case time complexity of O(n^2).
#include <stdio.h>

void selection_sort(int *arr, int n){          //Here we take the first element and compare it with the subarray infront of it.
    for (int i = 0;i < n-1; i++){              //when the element is found to be larger than an element in the subarray,
        for (int j = i+1 ; j < n ; j++){       //They are made to swap with each other and after the swaping, the element is once
            if (arr[i]>arr[j]){                // compared to the next element of the subarray.
            int temp = arr[i];
            arr[i] = arr[j];                   //This makes sure that after each iteration, the smallest element is at the correct index
            arr[j] = temp;
            }
        }
    }
}

void Print(int arr[], int n){
    for (int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n ; i++){
        printf("Enter the %d element: ",i+1);
        scanf("%d",&arr[i]);
    }
    printf("The elements of the array before insertion sorting: ");
    Print(arr,n);
    selection_sort(arr,n);
    printf("The elements of the array after insertion sorting; ");
    Print(arr,n);
}
