//I solved this after seeing all the hints
//But i got it to have 2ms runtime and Time Complexity of O(N).
int removeDuplicates(int* nums, int numsSize) {
    int k = 1;             // I made a mistake here, by first initialising it to 0
    int i = 0;
    for (int j = 1; j < numsSize ; j++){
        if (nums[i] != nums[j]){
            nums[++i] = nums[j];
            k++;          // The output is shown based on k as the array size
        }
    }
    return k;
}
