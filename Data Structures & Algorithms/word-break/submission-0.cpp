class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dictionary(
            wordDict.begin(),
            wordDict.end()
        );

        int maxWordLength = 0;
        for (const string& word : wordDict) {
            maxWordLength = max(
                maxWordLength,
                static_cast<int>(word.length())
            );
        }

        vector<bool> canBreak(s.length() + 1, false);
        canBreak[0] = true;

        for (int endIndex = 1; endIndex <= s.length(); ++endIndex) {
            int startLimit = max(0, endIndex - maxWordLength);

            for (
                int startIndex = startLimit;
                startIndex < endIndex;
                ++startIndex
            ) {
                if (!canBreak[startIndex]) {
                    continue;
                }

                string word = s.substr(
                    startIndex,
                    endIndex - startIndex
                );

                if (dictionary.contains(word)) {
                    canBreak[endIndex] = true;
                    break;
                }
            }
        }

        return canBreak[s.length()];
    }
};
