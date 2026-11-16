// class Solution {
// public:
//     int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        
//     }
// };


class Solution {
public:
    int mod = 1e9 + 7;
    int dp[51][51][51];

    int solve(int i, int j, int moves, int m, int n) {

        if (i < 0 || j < 0 || i >= m || j >= n)
            return 1;

        if (moves == 0)
            return 0;

        if (dp[i][j][moves] != -1)
            return dp[i][j][moves];

        long long ans = 0;

        ans = (ans + solve(i - 1, j, moves - 1, m, n)) % mod;
        ans = (ans + solve(i + 1, j, moves - 1, m, n)) % mod;
        ans = (ans + solve(i, j - 1, moves - 1, m, n)) % mod;
        ans = (ans + solve(i, j + 1, moves - 1, m, n)) % mod;

        return dp[i][j][moves] = ans;
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {

        memset(dp, -1, sizeof(dp));

        return solve(startRow, startColumn, maxMove, m, n);
    }
};
