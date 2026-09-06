class Solution {
public:
    int solve(int n, vector<int > & dp) {
        if(n==0) return 0;
        if(dp[n] !=-1) return dp[n];
        int minSquares =INT_MAX;
        for(int i=1; i*i<=n; i++){
            int subProblem = solve (n-i*i, dp);
            minSquares= min(minSquares, 1+ subProblem);

        }
         return dp[n]= minSquares;
    }
    int numSquares(int n) {
         vector<int> dp(n+1,-1);
         return solve(n,dp);
    }
};