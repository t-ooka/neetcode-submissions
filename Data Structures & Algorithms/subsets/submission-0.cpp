class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;

        dfs(nums, 0, current, result);
        return result;
    }

private:
    void dfs(
        const vector<int>& nums,
        int start,
        vector<int>& current,
        vector<vector<int>>& result
    ) {
        result.push_back(current);

        for (int index = start; index < nums.size(); ++index) {
            current.push_back(nums[index]);
            dfs(nums, index + 1, current, result);
            current.pop_back();
        }
    }
};
