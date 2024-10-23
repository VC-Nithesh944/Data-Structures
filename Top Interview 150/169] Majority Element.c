//This has a runtime of 0ms and Time complexity of O(N) and Space complexity of O(1) beats 100% in C.
//This utilises Booyer - Moore Voting algorithm.
int majorityElement(int* nums, int numsSize) {
    int count = 0;
    int candidate = 0;

    for(int i =0; i<numsSize;i++){
    if (count == 0){                   //When initialise first element or new element when occurs more than current element as candidate
        candidate = nums[i];
    }
    if (candidate == nums[i]){         //if Encountered with same numbers, increment the count size.
        count++;
    }
    else{
        count--;                       //if encountered with different numbers, decrement the count size.
    }
    }
    return candidate;
}
