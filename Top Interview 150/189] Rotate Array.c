//I am happy that this passed 37/38 testcases and then time exceeded.
// void rotate(int* nums, int numsSize, int k) {
//     for(int i = 0 ; i<k;i++){
//         int temp = nums[numsSize-1];
//         for(int i = numsSize-1 ; i > 0 ; i--){
//             nums[i] = nums[i-1];
//         }
//         nums[0] = temp;
//     }
// }

//This code has runtime of 0ms and Time complexity of O(N) and Space complexity of O(N).
void reverse(int *arr, int start , int end){
    while (start< end){
        int temp;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
void rotate(int* nums, int numsSize, int k) {
    if (numsSize == 1){           //if size of Array is 1 then just return it reduces average runtime
        return;
    }
    k= k%numsSize;                //The case where K is greater than Numsize.
    reverse(nums,0,numsSize-1);   //First reverse the entire array.

    reverse(nums,0,k-1);          //Reverse the first k element

    reverse(nums,k,numsSize-1);   //Reverse the remaining elements at a time.
}
