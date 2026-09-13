class Solution {
public:
    bool isPalindrome(int x) {
        if ( x<0 ) return false ;
        string  s= to_string(x);
        int i=0;
        int j= s.length()-1;
        while( i< j){
             if ( s[i] != s[j]){
                return false ;
             }
             j--;
             i++;
        }
         return true ;
    }
};