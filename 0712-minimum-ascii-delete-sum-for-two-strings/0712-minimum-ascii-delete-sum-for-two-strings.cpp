class Solution {
public:
    int solve(string& s1, string& s2, int n, int m, vector<vector<int>>& dp) {
        if (n < 0 && m >= 0) {
            int ans = 0;
            while (m >= 0) {
                ans += s2[m--];
            }
            return ans;
        } else if (m < 0 && n >= 0) {
            int ans = 0;
            while (n >= 0) {
                ans += s1[n--];
            }
            return ans;
        } else if (n < 0 && m < 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (s1[n] == s2[m]) {
            return dp[n][m] = solve(s1, s2, n - 1, m - 1, dp);
        } else {
            return dp[n][m] = min(solve(s1, s2, n - 1, m, dp) + s1[n], solve(s1, s2, n, m - 1, dp) + s2[m]);
        }
    }

    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(s1, s2, n - 1, m - 1, dp);
    }
};


