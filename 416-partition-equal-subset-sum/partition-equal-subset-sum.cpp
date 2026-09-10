class Solution {
public:
    bool solve(int i, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (target == 0) return true;
        if (i >= nums.size() || target < 0) return false;
        if (dp[i][target] != -1) {
            return dp[i][target]; 
        }
        bool include = false;
        if (target >= nums[i]) {
        include = solve(i + 1, target - nums[i], nums, dp);
        }
        bool exclude = solve(i + 1, target, nums, dp);
        return dp[i][target] = include || exclude;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        for (int num : nums) {
            totalSum += num;
        }
        if (totalSum % 2 != 0) return false;
        int target = totalSum / 2;
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        return solve(0, target, nums, dp);
    }
};