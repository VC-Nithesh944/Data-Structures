int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int *result= (int*)malloc(nums1Size*sizeof(int));                //This is by Brute Force Method , Question Number 496 of leet code
    for(int i=0;i<nums1Size;i++){
        for(int j=0;j<nums2Size;j++){
            if(nums1[i] == nums2[j]){
                if(j==nums2Size-1){                                  //if nums2[j] is the last element of the array then go for the next iteration
                    result[i] = -1;                                  
                    continue;
                }
                for(int k=j+1;k<nums2Size;k++){                     //check for greater element in nums2
                    if(nums2[k]>nums2[j]){
                        result[i] = nums2[k];
                        break;
                    }
                    if(k == nums2Size-1){                           //If nums2[k] is the last element of array, then assign -1
                        result[i] = -1;
                    }
                }
            }
        }
    }
    *returnSize = nums2Size;
    return result;
}
