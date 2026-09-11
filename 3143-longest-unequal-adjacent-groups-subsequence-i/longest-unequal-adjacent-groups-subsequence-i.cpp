class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> prev(n, -1);
        
        int maxLen = 1;
        int bestEnd = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                bestEnd = i;
            }
        }
        
        vector<string> result;
        int curr = bestEnd;
        while (curr != -1) {
            result.push_back(words[curr]);
            curr = prev[curr];
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};