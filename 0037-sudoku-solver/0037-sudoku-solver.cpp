class Solution {
public:
    bool notclash(char num, int i, int j, vector<vector<char>>& board, int n) {
        for (int k = 0; k < n; k++) {
            // row
            if (board[i][k] == num) return false;
            // column
            if (board[k][j] == num) return false;
        }

        // box
        int s = sqrt(n);
        int startrow = i - i % s;
        int startcol = j - j % s;

        for (int r = startrow; r < startrow + s; r++) {
            for (int c = startcol; c < startcol + s; c++) {
                if (board[r][c] == num) return false;
            }
        }

        return true;
    }

    bool solveboard(std::vector<vector<char>>& board, int n) {
        bool flag = false;
        int i, j;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                // we have to fill this cell
                if (board[i][j] == '.') {
                    flag = true;
                    break;
                }
            }
            if (flag) break;
        }

        if (i == n && j == n) return true;

        // i, j -> fill the value
        for (int num = 1; num <= n; num++) {
            // convert the number to char
            char numChar = num + '0';

            // check if not clashing
            if (notclash(numChar, i, j, board, n)) {
                board[i][j] = numChar;
                if (solveboard(board, n)) return true;
                board[i][j] = '.';
            }
        }

        return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n = board.size();
        solveboard(board, n);
    }
};