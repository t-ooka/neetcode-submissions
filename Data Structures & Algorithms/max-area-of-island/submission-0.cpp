class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int maxArea = 0;

        vector<pair<int, int>> dirs = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] == 0) {
                    continue;
                }

                int area = 0;
                stack<pair<int, int>> st;
                st.push({r, c});
                grid[r][c] = 0;

                while (!st.empty()) {
                    auto [row, col] = st.top();
                    st.pop();
                    area++;

                    for (auto [dr, dc] : dirs) {
                        int nr = row + dr;
                        int nc = col + dc;

                        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                            continue;
                        }
                        if (grid[nr][nc] == 0) {
                            continue;
                        }

                        grid[nr][nc] = 0;
                        st.push({nr, nc});
                    }
                }

                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
