#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Helper function to check if an element exists in an array
bool exists_in_array(int* arr, int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

// Function to find distinct elements between nums1 and nums2
int** findDifference(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize, int** returnColumnSizes) {
    // Allocate memory for result arrays
    int** result = (int**)malloc(2 * sizeof(int*));
    result[0] = (int*)malloc(nums1Size * sizeof(int)); // To store distinct elements from nums1
    result[1] = (int*)malloc(nums2Size * sizeof(int)); // To store distinct elements from nums2

    // Allocate memory for returnColumnSizes
    *returnColumnSizes = (int*)malloc(2 * sizeof(int));

    // Find elements in nums1 that are not in nums2
    int size1 = 0;
    for (int i = 0; i < nums1Size; i++) {
        if (!exists_in_array(nums2, nums2Size, nums1[i]) && !exists_in_array(result[0], size1, nums1[i])) {
            result[0][size1++] = nums1[i];
        }
    }

    // Find elements in nums2 that are not in nums1
    int size2 = 0;
    for (int i = 0; i < nums2Size; i++) {
        if (!exists_in_array(nums1, nums1Size, nums2[i]) && !exists_in_array(result[1], size2, nums2[i])) {
            result[1][size2++] = nums2[i];
        }
    }

    // Set the sizes of the result arrays in returnColumnSizes
    (*returnColumnSizes)[0] = size1;
    (*returnColumnSizes)[1] = size2;
    
    // Set returnSize to 2 (since there are two lists)
    *returnSize = 2;

    // Reallocate memory to match the exact number of distinct elements
    result[0] = (int*)realloc(result[0], size1 * sizeof(int));
    result[1] = (int*)realloc(result[1], size2 * sizeof(int));

    return result;
}
