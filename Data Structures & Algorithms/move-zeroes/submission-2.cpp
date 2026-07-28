class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;

        for (int num : nums) {
            if (num == 0) {
                continue;
            }

            nums[write] = num;
            ++write;
        }

        while (write < nums.size()) {
            nums[write] = 0;
            ++write;
        }
    }
};