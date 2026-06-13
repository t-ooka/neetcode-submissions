class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_to_idx;

        for (int i = 0; i < nums.size(); i++) {
            if (num_to_idx.find(target - nums[i]) != num_to_idx.end()) {
                return { num_to_idx[target - nums[i]], i};
            }
            num_to_idx.insert({nums[i], i});
        }

        return {};
    }
};
