class Solution {
public:
 int solve( int i, int currentSum, int target, vector<int> & stones, vector<vector<int >> & dp){
    if(i ==stones .size() ){
         return currentSum;
    }
     if ( dp[i][currentSum] != -1){
         return dp[i][currentSum];
     }
     int exclude = solve (i+1, currentSum, target,stones, dp);
     int include =0;
     if (currentSum + stones[i] <= target) {
        include = solve ( i+1,  currentSum+stones[i],target,stones, dp);
     }
      return  dp[i][currentSum]= max( include , exclude );
 }
    int lastStoneWeightII(vector<int>& stones) {
         int totalSum = accumulate ( stones. begin(), stones.end(), 0);
         int target= totalSum/ 2;
         int n= stones .size();
         vector<vector<int>> dp(n, vector<int>(target + 1, -1));
         int s1 = solve(0, 0, target, stones, dp);
         return totalSum - 2 * s1;
    }
};