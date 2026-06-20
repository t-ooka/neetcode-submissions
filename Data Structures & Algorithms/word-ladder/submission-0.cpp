class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord)) {
            return 0;
        }

        unordered_set<string> front{beginWord};
        unordered_set<string> back{endWord};

        words.erase(beginWord);
        words.erase(endWord);

        int steps = 1;

        while (!front.empty() && !back.empty()) {
            if (front.size() > back.size()) {
                swap(front, back);
            }

            unordered_set<string> nextFront;

            for (string word : front) {
                for (int i = 0; i < word.size(); i++) {
                    char original = word[i];

                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == original) {
                            continue;
                        }

                        word[i] = c;

                        if (back.count(word)) {
                            return steps + 1;
                        }

                        if (words.erase(word)) {
                            nextFront.insert(word);
                        }
                    }

                    word[i] = original;
                }
            }

            front = move(nextFront);
            steps++;
        }

        return 0;
        
    }
};
