class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> last_seen(256, -1);

        int left = 0;
        int best = 0;
        int n = s.length();

        for (int right = 0; right < n; ++right) {
            char current_char = s[right];

            if (last_seen[current_char] >= left) {
                left = last_seen[current_char] + 1;
            }

            last_seen[current_char] = right;
            best = std::max(best, right - left + 1);
        }
        return best;
    }
};
