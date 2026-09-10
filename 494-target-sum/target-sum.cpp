class Solution {
public:
 int solve (vector<int>& nums, int target,int i,  vector<vector<int >> & dp){
    if(i==0 ){
        if( target ==0  && nums[0] ==0) return 2;
        if( target  ==0 || target == nums[0]) return 1;
        return 0;
    }
  if( dp[i][target]!= -1){
     return dp[i][target];
  }
  int skip = solve ( nums, target, i-1, dp);
   int pick= 0 ;
   if( nums[i]<= target){
    pick= solve ( nums, target- nums[i], i-1, dp);

   }
    return dp[i][target]= pick + skip;
 }
    int findTargetSumWays(vector<int>& nums, int target) {
        int totalSum =0; 
        for( int num : nums){
             totalSum += num;
        }
      if (totalSum < abs(target) || (totalSum + target) % 2 != 0) {
            return 0;
         }
// int subsetTarget= (totalSum + target)/2;
          int n= nums.size();
          int subsetTarget= (totalSum + target)/2;
      vector<vector<int>> dp(n, vector<int>(subsetTarget+1, -1));
       return solve ( nums, subsetTarget, n-1, dp);
    }
};