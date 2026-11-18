
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int i = 0;
        int cnt= 0;
        while (i < k) {
            if (blocks[i] == 'W') {
                cnt++;
            }
            i++;
        }
        int mini = cnt;
        int j = k;
        while (j < n) {
            if (blocks[j] == 'W') {
                cnt++;
            }
            if (blocks[j - k] == 'W') {
                cnt--;
            }
            mini = min(mini, cnt);
            j++;
        }
        return mini;
    }
};
