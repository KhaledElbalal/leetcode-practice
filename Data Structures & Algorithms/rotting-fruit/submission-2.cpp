class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;

        auto transform = [](int val) {
            if (val == 1) return 2;
            return val;
        };

        auto count_2d = [](const auto& matrix, int target) {
            return std::accumulate(matrix.begin(), matrix.end(), 0, 
            [target](int sum, const auto& row) {
                return sum + std::count(row.begin(), row.end(), target);
            });
        };


        int prevFreshCount = count_2d(grid, 1);
        if(prevFreshCount == 0) return 0;
        while(true) {
            ans++;
            vector<vector<int>> cp = grid;
            for(int i = 0; i < grid.size(); i++) {
                for(int j = 0; j < grid[0].size(); j++) {
                    if(grid[i][j] == 2) {
                        if(i > 0) cp[i-1][j] = transform(grid[i-1][j]);
                        if(j > 0) cp[i][j-1] = transform(grid[i][j-1]);
                        if(i + 1 < grid.size()) cp[i+1][j] = transform(grid[i+1][j]);
                        if(j + 1 < grid[0].size()) cp[i][j+1] = transform(grid[i][j+1]);
                    }
                }
            }
            grid = cp;
            int currFreshCount = count_2d(grid, 1);
            if(currFreshCount == prevFreshCount) return -1;
            if(currFreshCount == 0)              return ans;
            prevFreshCount = currFreshCount;
        } 
    }
};
