//This code has runtime of 0ms in java and Time complexity of O(N).
class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 1;         //Since the 0th index would always remain, this is used to assign the elements.
        int seen = 1;      //since the first element is already seen
        for(int j = 1; j < nums.length ; j++){
            if (nums[j] == nums[j-1]){
                seen++;
            }
            else{
                seen = 1; //reset when new element is encountered.
            }

            if(seen <= 2){
                nums[i] = nums[j]; //copy the element if seen less than 2 or 2 times.
                i++;
            }
        }
        return i;
    }
}
