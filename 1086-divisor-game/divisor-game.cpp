class Solution {
    private:
     int dp [1005];
      bool fun (  int n){
         if ( n==1 ) return false ;
          if (dp[n] != -1 ) return dp[n];
           for ( int i =1; i< n; ++i){
            if ( n% i== 0){
                 if (!fun( n-i)){
                     return dp[n] =1;
                 }
            }
           }
            return dp[n]= 0;
      }
public:
    bool divisorGame(int n) {
        memset( dp, -1, sizeof(dp));
        return fun(n);
        
    }
};