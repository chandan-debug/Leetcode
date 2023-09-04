class Solution {

private:
    bool inbound(int i, int j, int n) {
        return i >= 0 && i < n && j >= 0 && j < n;
    }

    bool issafe(int r, int c, const vector<string>& temp, int n) {
        // Check for row and column
        for (int k = 0; k < n; k++) {
            if (temp[k][c] == 'Q' || temp[r][k] == 'Q')
                return false;
        }
        // Check diagonals
        for (int l = 1; l < n; l++) {
            if (inbound(r - l, c - l, n) && temp[r - l][c - l] == 'Q') return false;
            if (inbound(r - l, c + l, n) && temp[r - l][c + l] == 'Q') return false;
            if (inbound(r + l, c - l, n) && temp[r + l][c - l] == 'Q') return false;
            if (inbound(r + l, c + l, n) && temp[r + l][c + l] == 'Q') return false;
        }
        return true;
    }

    void solve(int row, int n, vector<string>& temp, vector<vector<string>>& ans) {
        if (row == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (issafe(row, i, temp, n)) {
                temp[row][i] = 'Q';
                solve(row + 1, n, temp, ans);
                temp[row][i] = '.'; // backtrack
            }
        }
    }
    public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> temp(n, string(n, '.')); 
        solve(0, n, temp, ans);
        return ans;
    }
};