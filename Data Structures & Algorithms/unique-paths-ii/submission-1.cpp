class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        vector<vector<long long>> dp(rows, vector<long long>(cols, 0));
        dp[0][0] = obstacleGrid[0][0] == 1 ? 0 : 1;

        for (int row = 0; row < rows; ++row) {
            for (int col = 0; col < cols; ++col) {
                if (obstacleGrid[row][col] == 1) {
                    dp[row][col] = 0;
                    continue;
                }

                if (row == 0 && col == 0) {
                    continue;
                }

                long long fromTop = row > 0 ? dp[row - 1][col] : 0;
                long long fromLeft = col > 0 ? dp[row][col - 1] : 0;
                dp[row][col] = fromTop + fromLeft;
            }
        }

        return static_cast<int>(dp[rows - 1][cols - 1]);
    }
};