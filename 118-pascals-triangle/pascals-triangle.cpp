#include <vector>
using namespace std;
class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp) {
        if (j == 0 || j == i) {
            return 1;
        }
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        return dp[i][j] = solve(i - 1, j - 1, dp) + solve(i - 1, j, dp);
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> dp(numRows, vector<int>(numRows, -1));
        vector<vector<int>> result;
        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1);
            for (int j = 0; j <= i; ++j) {
                row[j] = solve(i, j, dp);
            }
            result.push_back(row);
        }
        return result;
    }
};