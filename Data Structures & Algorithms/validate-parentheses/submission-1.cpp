class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;

        for (char ch : s) {
            if (ch == '(') {
                stack.push_back(')');
            } else if (ch == '{') {
                stack.push_back('}');
            } else if (ch == '[') {
                stack.push_back(']');
            } else {
                if (stack.empty() || stack.back() != ch) {
                    return false;
                }
                stack.pop_back();
            }
        }
        return stack.empty();
    }
};
