class Solution {
public:
    int solve(int i, int j, int n, int m, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i == n - 1 && j == m - 1) // Base case for reaching the bottom-right cell
            return grid[i][j];
        
        if (i >= n || j >= m) // Base case for out of bounds cells
            return INT_MAX;
        
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int rightSum = solve(i + 1, j, n, m, grid, dp);
        int downSum = solve(i, j + 1, n, m, grid, dp);

        return dp[i][j] = grid[i][j] + min(rightSum, downSum);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(0, 0, m, n, grid, dp);
    }
};
