#include <vector>
#include <numeric>
#include <algorithm>

class Solution {
    bool solve(int index, int current_sum, int target, int k, const std::vector<int>& nums, std::vector<bool>& visited) {
        if (k == 1) return true;

        if (current_sum == target) {
            return solve(0, 0, target, k - 1, nums, visited);
        }

        for (int i = index; i < nums.size(); ++i) {
            if (!visited[i]) {
                if (current_sum + nums[i] > target) continue;

                visited[i] = true;
                if (solve(i + 1, current_sum + nums[i], target, k, nums, visited)) {
                    return true;
                }
                visited[i] = false;
            }
        }

        return false;
    }

public:
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        int total_sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (total_sum % k != 0) return false;

        int target = total_sum / k;
        std::sort(nums.rbegin(), nums.rend());
        if (nums[0] > target) return false;

        std::vector<bool> visited(nums.size(), false);
        return solve(0, 0, target, k, nums, visited);
    }
};