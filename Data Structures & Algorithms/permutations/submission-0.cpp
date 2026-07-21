class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutations;
        vector<int> permutation;
        vector<bool> used(nums.size(), false);

        dfs(nums, used, permutation, permutations);

        return permutations;
    }

private:
    void dfs(
        const vector<int>& nums,
        vector<bool>& used,
        vector<int>& permutation,
        vector<vector<int>>& permutations
    ) {
        if (permutation.size() == nums.size()) {
            permutations.push_back(permutation);
            return;
        }

        for (int index = 0; index < nums.size(); ++index) {
            if (used[index]) {
                continue;
            }

            used[index] = true;
            permutation.push_back(nums[index]);

            dfs(nums, used, permutation, permutations);

            permutation.pop_back();
            used[index] = false;
        }
    }
};
