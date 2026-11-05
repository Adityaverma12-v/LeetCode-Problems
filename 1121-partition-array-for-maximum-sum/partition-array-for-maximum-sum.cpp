class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n= arr.size();
  vector<int> dp(n + 1, 0);

        for ( int i= 0; i<= n; i++){
            int ans=0;
            for ( int gap = 1;gap<= k && gap<=i;gap++){
                ans = max( ans,arr[i-gap]);
                int sum = dp[i-gap]+ans*gap; 
                dp[i] = max(dp[i], sum);
            }
        }
        return dp[n];
    }
};