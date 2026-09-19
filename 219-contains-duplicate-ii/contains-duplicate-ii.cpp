class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        vector<pair<int, int>> Value;
        for (int i = 0; i < nums.size(); ++i) {
            Value.push_back({nums[i], i});
        }
        
        sort(Value.begin(), Value.end());
        
        for (int i = 0; i + 1 < Value.size(); ++i) {
            if (Value[i].first == Value[i + 1].first && 
                abs(Value[i].second - Value[i + 1].second) <= k) {
                return true;
            }
        }
        
        return false;
    }
};