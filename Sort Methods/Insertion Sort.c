//Insertion sorting has worst and average time complexity of O(n^2).
//But has the Best Time Complexity as O(n) when all the elements are in ascending order.
//And no Additional changes in the code is needed to make it O(n).
#include <stdio.h>

void insertion_sort(int *arr, int n){
    for (int i = 1; i < n; i++){            //Taking consideration of element to be sorted
        int j = i - 1;                      //Gives the index of Last sorted subarray
        int key = arr[i];                   //assigning the element to temp variable so that code doesn't overwrite
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];              //shifting of larger elements to right
            j--;
        }
        arr[j+1] = key;                     //inserting the element to its correct position
    }
}

void Print(int arr[], int n){
    for (int i = 0 ; i < n ; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {                               //This is all basics and I know about it
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
    insertion_sort(arr,n);
    printf("The elements of the array after insertion sorting; ");
    Print(arr,n);
}
