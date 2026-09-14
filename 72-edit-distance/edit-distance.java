class Solution {
    //  private :
      int solve ( int i, int j,String word1, String word2, int [][] dp){
         if (i==0 ) return j;
         if (j==0 ) return i;
          if ( dp [i][j] != -1) return dp [i][j];
          if (word1.charAt(i - 1) == word2.charAt(j - 1)) {
            return dp[i][j] = solve(i - 1, j - 1, word1, word2, dp);
        }
        int insertOp = solve(i, j - 1, word1, word2, dp);
        int deleteOp = solve(i - 1, j, word1, word2, dp);
        int replaceOp = solve(i - 1, j - 1, word1, word2, dp);

        return dp[i][j] = 1 + Math.min(insertOp, Math.min(deleteOp, replaceOp));
    }

    public int minDistance(String word1, String word2) {
        int m = word1.length();
        int n = word2.length();
        int[][] dp = new int[m + 1][n + 1];
        for (int[] row : dp) {
            Arrays.fill(row, -1);
        }

        return solve(m, n, word1, word2, dp);
    }
}
      