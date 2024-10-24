//This has a runtime of 0ms in C and Time complexity of O(N).
//I used Kadane's algorithm , I had solved this also during the leetcode camp.
int maxSubArray(int* nums, int numsSize) {
    int sum = 0;
    int max = -10000;                 //Assigning the minimum possible constraint possible
    for (int i = 0; i<numsSize;i++){
        sum += nums[i];
        if(max<sum){                  //if Sum is greater than max then max is given the value of sum, the next time if its not true
            max = sum;                //Then sum would be considered until it goes less then 0
        }
        if(sum <0){                   //Once it goes below 0 then its reset to 0.
            sum = 0;
        }
    }                                //This done because we don't want to consider the subarray which makes our sum decreases
    return max;
}
