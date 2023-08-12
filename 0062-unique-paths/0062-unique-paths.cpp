 class Solution {
public:
    int uniquePaths(int m, int n, int i, int j,vector<vector<int>>& dp) {
        if (i >= m || j >= n)
            return 0;
        
        if (i == m - 1 && j == n - 1)
            return 1;
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        
        return dp[i][j]=uniquePaths(m, n, i + 1, j,dp) + uniquePaths(m, n, i, j + 1,dp);
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        return uniquePaths(m, n, 0, 0,dp);
    }
};

        