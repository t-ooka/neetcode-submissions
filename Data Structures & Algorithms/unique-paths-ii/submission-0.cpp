class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int cols = obstacleGrid[0].size();

        const long long LIMIT = 2000000001LL;
        vector<long long> dp(cols, 0);
        dp[0] = 1;

        for (const auto& row : obstacleGrid) {
            for (int col = 0; col < cols; ++col) {
                if (row[col] == 1) {
                    dp[col] = 0;
                } else if (col > 0) {
                    dp[col] = min(LIMIT, dp[col] + dp[col - 1]);
                }
            }
        }

        return static_cast<int>(dp.back());
    }
};