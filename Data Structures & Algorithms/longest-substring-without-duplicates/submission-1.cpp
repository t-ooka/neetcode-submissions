class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen_chars;
        int left = 0;
        int best = 0;

        for (int right = 0; right < s.size(); right++) {
            while (seen_chars.find(s[right]) != seen_chars.end()) {
                seen_chars.erase(s[left]);
                ++left;
            }
            seen_chars.insert(s[right]);
            best = max(best, right - left + 1);
        }
        return best;
    }
};
