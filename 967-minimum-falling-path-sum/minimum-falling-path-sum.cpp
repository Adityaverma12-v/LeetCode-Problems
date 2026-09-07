class Solution {
public:
    int solve(int row, int col, int n,vector<vector<int>>& matrix,vector<vector<int>>& dp) {
        if (col < 0 || col >= n)return 1e9;
        if (row == 0)return matrix[0][col];
        if (dp[row][col] != -1e9)return dp[row][col];
        int straight = matrix[row][col] +solve(row - 1, col, n, matrix, dp);
        int left = matrix[row][col] +solve(row - 1, col - 1, n, matrix, dp);
        int right = matrix[row][col] +solve(row - 1, col + 1, n, matrix, dp);
        return dp[row][col] = min({straight, left, right});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        int minSum = INT_MAX;
        for (int col = 0; col < n; col++) {
            minSum = min(minSum,solve(n - 1, col, n, matrix, dp));
        }
        return minSum;
    }
};