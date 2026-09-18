class Solution {
public:
 int fxn( int x, int last , int n, vector <int > & dp ){
     if ( x >  last) return 0;
      if (dp[x]!= -1) return dp[x];
       int curr= ((n & x)== 0)? x: 0;
       return dp[x]= curr+  fxn ( x+1,last , n, dp );
 }
    int sumOfGoodIntegers(int n, int k) {
        int first = max(1, n-k);
        int last = n+k;
         vector<int > dp(last+1, -1);
          return fxn( first, last, n, dp);
    }
};