class Solution {
    public int removeDuplicates(int[] nums) {

        int n = 0;
        
        for(int i =1;i<nums.length;i++){

            if(nums[i]>nums[n]){
                nums[n+1] = nums[i];
                n++;
            }
        }

        return n+1;
        
    }
}