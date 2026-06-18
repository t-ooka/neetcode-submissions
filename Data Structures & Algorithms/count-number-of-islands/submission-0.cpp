class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;

        vector<pair<int, int>> directions = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}
        };

        for (int r = 0; r < rows; r++) {
            for (int c = 0; c < cols; c++) {
                if (grid[r][c] != '1') {
                    continue;
                }

                islands++;
                grid[r][c] = '0';

                stack<pair<int, int>> st;
                st.push({r, c});

                while (!st.empty()) {
                    auto [row, col] = st.top();
                    st.pop();

                    for (auto [dr, dc] : directions) {
                        int nr = row + dr;
                        int nc = col + dc;

                        if (nr < 0 || nr >= rows || nc < 0 || nc >= cols) {
                            continue;
                        }
                        if (grid[nr][nc] != '1') {
                            continue;
                        }

                        grid[nr][nc] = '0';
                        st.push({nr, nc});
                    }
                }
            }
        }

        return islands;
    }
};
