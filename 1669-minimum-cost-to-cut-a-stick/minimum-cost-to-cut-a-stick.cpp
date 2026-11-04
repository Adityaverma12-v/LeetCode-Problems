class Solution {
public:
 int  function( int i , int j, vector< int > & cuts, vector<vector<int>> & dp ){
      if (i+1 == j) return 0;
       if( dp[i][j] != -1) return dp[i][j];
        int ans = INT_MAX;
         for( int k = i+1; k<j ; k++){
             int cost=  function(i, k , cuts, dp)+ function(k, j,cuts, dp) + cuts[j]- cuts[i];
              ans = min( ans, cost);
         }
        return dp[i][j]= ans;
     
 }
 int minCost(int n, vector<int>& cuts) {
     cuts.push_back(0);
     cuts.push_back(n);
    sort(cuts.begin(), cuts.end());
     int m= cuts.size();
    vector<vector< int >>dp(m, vector<int > (m, -1));
     return function( 0 , m-1, cuts , dp);
 }
};