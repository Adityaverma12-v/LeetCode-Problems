#include <vector>
#include <algorithm>

class Solution {
    int solve(int i, int buy, std::vector<int>& prices, std::vector<std::vector<int>>& dp) {
        if (i >= prices.size()) return 0;
        if (dp[i][buy] != -1) return dp[i][buy];

        if (buy == 1) {
            dp[i][buy] = std::max(-prices[i] + solve(i + 1, 0, prices, dp),
                                  0 + solve(i + 1, 1, prices, dp));
        } else {
            dp[i][buy] = std::max(prices[i],  0 + solve(i + 1, 0, prices, dp));
        }

        return dp[i][buy];
    }

public:
    int maxProfit(std::vector<int>& prices) {
        int n = prices.size();
        std::vector<std::vector<int>> dp(n, std::vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};