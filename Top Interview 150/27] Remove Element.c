//The first ever coding question that i completely solved independently
//and this has 0ms runtime and beats 100%.

int removeElement(int* nums, int numsSize, int val) {
    int k = 0;
    int i = numsSize - 1;
    int j = i;
    int temp;
    while (j>= 0){
        if(nums[j] == val){
            temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
            i--;
            j--;
        }
        else{
            j--;
            k++;
        }
    }
    return k;
}
