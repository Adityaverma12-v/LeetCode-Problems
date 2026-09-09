class Solution {
public:
 int solve ( vector<int>& coins, int amount, vector<int> & dp){
    if ( amount ==0 ) return 0 ;
    if(dp[amount] != - 1) return dp[amount] ;
     int minCoins =INT_MAX;
    for(int coin : coins ) {
      if( amount - coin >= 0) {
        int ans = solve ( coins, amount - coin, dp);
        if(ans != INT_MAX){
            minCoins = min(minCoins, 1 + ans); 
        }
      }

    }
     return dp[amount]= minCoins;
 }
    int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, -1);
 
    int ans = solve( coins , amount, dp );
    if (ans == INT_MAX)
        return -1;

    return ans;
    }
};