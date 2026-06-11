class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int, int> num_to_idx;

        for (int i = 0; i < n; i++) {
            int diff = target - nums[i];

            if (num_to_idx.find(diff) != num_to_idx.end()) {
                return {  num_to_idx[diff], i};
            }
            num_to_idx.insert({nums[i], i});
        }
        return {};
    }
};
