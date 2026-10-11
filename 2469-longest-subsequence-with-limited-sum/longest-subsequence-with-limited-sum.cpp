class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());

        for (int i = 1; i < nums.size(); i++) {
            nums[i] += nums[i - 1];
        }

        for (int i = 0; i < queries.size(); i++) {
            int l = 0, r = nums.size() - 1;
            int cnt = 0;

            while (l <= r) {
                int mid = l + (r - l) / 2;

                if (nums[mid] <= queries[i]) {
                    cnt = mid + 1;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }

            ans.push_back(cnt);
        }

        return ans;
    }
};