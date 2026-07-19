class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> chars;
        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < static_cast<int>(s.size()); ++right) {
            while (chars.contains(s[right])) {
                chars.erase(s[left]);
                ++left;
            }

            chars.insert(s[right]);
            maxLength = max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};
