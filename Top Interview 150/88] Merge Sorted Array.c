//This has runtime of 0ms and time complexity of O(m+n).

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    int i = m - 1;  // Pointer to the last valid element in nums1
    int j = n - 1;  // Pointer to the last element in nums2
    int k = nums1Size - 1;  // Pointer to the last position in nums1

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums2[j--];
        }
    }

    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}
