class Solution {
public:
    // Function to calculate the probability of a knight staying on the chessboard after 'k' moves.
    double knightProbability(int n, int k, int row, int col) {
        // Create a 3D DP array to store the results of subproblems.
        // dp[row][col][moves] will store the probability of the knight staying at position (row, col) after 'moves' moves.
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, -1)));
        return solve(n, row, col, k, dp);
    }

    // Recursive function to calculate the probability of a knight staying on the chessboard.
    double solve(int n, int row, int col, int k, vector<vector<vector<double>>>& dp) {
        // Base case 1: If the knight moves out of the chessboard, return 0.
        if (row < 0 || row >= n || col < 0 || col >= n || k < 0) {
            return 0;
        }
        // Base case 2: If no more moves are left (k=0), return 1. The knight is guaranteed to stay on the board after making 0 moves.
        if (k == 0) {
            return 1;
        }
        // If the probability for this position and 'k' moves is already calculated, return it from the DP array.
        if (dp[row][col][k] != -1) {
            return dp[row][col][k];
        }

        // Array representing possible changes in row and column positions for a knight's move.
        int delrow[8] = { -2, -2, -1, +1, +2, +2, +1, -1 };
        int delcol[8] = { -1, +1, +2, +2, +1, -1, -2, -2 };

        double ans = 0;
        // Calculate the probability of the knight staying on the chessboard after 'k-1' moves from all 8 possible moves.
        for (int i = 0; i < 8; i++) {
            int nrow = delrow[i] + row; // New row position after the move.
            int ncol = delcol[i] + col; // New column position after the move.
            ans += (0.125 * solve(n, nrow, ncol, k - 1, dp)); // Each move has a probability of 0.125 (1/8).
        }

        // Memoize the result and return the probability for this position and 'k' moves.
        return dp[row][col][k] = ans;
    }
};