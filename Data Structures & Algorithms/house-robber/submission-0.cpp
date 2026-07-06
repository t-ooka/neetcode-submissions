class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);

        function<int(int)> dfs = [&](int i) {
            if (i >= nums.size()) {
                return 0;
            }
            if (memo[i] != -1) {
                return memo[i];
            }

            int rob_current = nums[i] + dfs(i + 2);
            int skip_current = dfs(i + 1);

            memo[i] = max(rob_current, skip_current);
            return memo[i];
        };

        return dfs(0);
    }
};
