class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int minLength = nums.size() + 1;
        long long windowSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            windowSum += nums[right];

            while (windowSum >= target) {
                int currentLength = right - left + 1;
                minLength = min(minLength, currentLength);

                windowSum -= nums[left];
                ++left;
            }
        }

        return minLength == nums.size() + 1 ? 0 : minLength;
    }
};