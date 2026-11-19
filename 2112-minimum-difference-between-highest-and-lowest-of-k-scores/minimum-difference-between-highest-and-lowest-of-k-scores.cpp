class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        int i=0;
        int res= INT_MAX;
        while (i + k - 1 < n) {
            int diff = nums[i + k - 1] - nums[i];

            res= min(res, diff);

            i++;
        }

        return res;
    }
};