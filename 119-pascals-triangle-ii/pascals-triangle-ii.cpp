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

    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex + 1, vector<int>(rowIndex + 1, -1));

        vector<int> row(rowIndex + 1);

        for (int j = 0; j <= rowIndex; j++) {
            row[j] = solve(rowIndex, j, dp);
        }

        return row;
    }
};