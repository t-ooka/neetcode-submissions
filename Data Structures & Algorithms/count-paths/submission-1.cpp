class Solution {
public:
    int uniquePaths(int m, int n) {
        int totalSteps = m + n - 2;
        int choose = min(m - 1, n - 1);

        long long result = 1;

        for (int i = 1; i <= choose; ++i) {
            result = result * (totalSteps - choose + i) / i;
        }

        return static_cast<int>(result);
    }
};
