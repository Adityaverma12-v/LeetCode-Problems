class Solution {
    int solve(int i, int index, vector<int>& nums, vector<vector<int>>& dp, vector<vector<int>>& choice) {
        if (i == nums.size()) return 0;

        if (dp[i][index + 1] != -1) return dp[i][index + 1];

        int not_take = solve(i + 1, index, nums, dp, choice);

        int take = 0;
        if (index == -1 || nums[i] % nums[index] == 0) {
            take = 1 + solve(i + 1, i, nums, dp, choice);
        }

        if (take > not_take) {
            choice[i][index + 1] = 1;
            return dp[i][index + 1] = take;
        } else {
            choice[i][index + 1] = 0;
            return dp[i][index + 1] = not_take;
        }
    }

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        vector<vector<int>> choice(n, vector<int>(n + 1, -1));

        solve(0, -1, nums, dp, choice);

        vector<int> result;
        int i = 0, index = -1;
        while (i < n) {
            if (choice[i][index + 1] == 1) {
                result.push_back(nums[i]);
                index = i;
            }
            i++;
        }

        return result;
    }
};