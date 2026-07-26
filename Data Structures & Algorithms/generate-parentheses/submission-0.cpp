class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;

        backtrack(n, 0, 0, current, result);
        return result;
    }

private:
    void backtrack(
        int n,
        int open_count,
        int close_count,
        string& current,
        vector<string>& result
    ) {
        if (open_count == n && close_count == n) {
            result.push_back(current);
            return;
        }

        if (open_count < n) {
            current.push_back('(');

            backtrack(
                n,
                open_count + 1,
                close_count,
                current,
                result
            );

            current.pop_back();
        }

        if (close_count < open_count) {
            current.push_back(')');

            backtrack(
                n,
                open_count,
                close_count + 1,
                current,
                result
            );

            current.pop_back();
        }
    }
};
