class Solution {
public:
     int helper(int i, vector<int>& nums, vector<int>&dp){
        int n= nums.size();
        if(i>= n-1) return 0;
        if(dp[i] != -1){
            return dp[i];
        }
        int minJumps = INT_MAX;
        for(int j= 1; j<= nums[i];j++){
            int next = helper(i + j, nums, dp);
            if(next != INT_MAX) {
                int jumps = 1 + next;
                minJumps = min(minJumps, jumps);
        }
        }
        return dp[i] = minJumps;
     }
    int jump(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n, -1);
        return helper (0,nums,dp);
    }
};