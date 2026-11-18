class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n= nums.size();
        double sum = 0;
        int i=0;
         while (i < k) {
            sum += nums[i];
            i++;
        }
        double maxi = sum;
        int j = k;
        while (j < n) {
            sum += nums[j];
            sum -= nums[j - k];

            maxi = max(maxi, sum);

            j++;
        }
        return maxi / k;
    }
};
    