import java.util.HashMap;
class Solution {
    public int longestPalindrome(String s) {
        HashMap< Character,Integer > countMap= new HashMap<>();
         for ( char c: s.toCharArray()){
countMap.put(c, countMap.getOrDefault(c, 0) + 1);         }
          int length =0;
           boolean hasodd= false;
            for ( int count : countMap.values()){
                length+= ( count/ 2)* 2;
                 if ( count  % 2== 1){
                    hasodd= true;
                 }
            }
             if ( hasodd){
                 length+= 1;
             }
              return length;
    }
}