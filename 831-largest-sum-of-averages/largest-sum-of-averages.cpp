

class Solution {
    double largestSumOfAveragesHelper(vector<int>& nums, int k, int start, vector<vector<double>>& dp) {
        if (k == 0 && start == nums.size()) return 0;
        if (k == 0 || start == nums.size()) return -1e9;
        if (dp[start][k] != -1) return dp[start][k];

        double currSum = 0, maxAverage = -1e9;
        for (int i = start; i < nums.size(); ++i) {
            currSum += nums[i];
            double average = currSum / (i - start + 1);
            maxAverage = max(maxAverage, average + largestSumOfAveragesHelper(nums, k - 1, i + 1, dp));
        }

         dp[start][k] = maxAverage;
         return dp[start][k] ; 
    }
public:
    double largestSumOfAverages(vector<int>& nums, int k) {
        vector<vector<double>> dp(nums.size(), vector<double>(k + 1, -1));
        return largestSumOfAveragesHelper(nums, k, 0, dp);
    }
};