class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> counts;
        int max_count;
        int best = 0;
        int left = 0;

        for (int right = 0; right < s.size(); right++) {
            ++counts[s[right]];
            max_count = max(max_count, counts[s[right]]);

            if ((right - left + 1) - max_count > k) {
                --counts[s[left]];
                left += 1;
            }

            best = max(best, right - left + 1);
        }

        return best;
    }
};
