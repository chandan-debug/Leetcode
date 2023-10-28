class Solution {
    const int mod = 1e9 + 7;
public:
    int countVowelPermutation(int n) {
        vector<vector<int>> DP(5, vector<int>(n));
        DP[0][0] = DP[1][0] = DP[2][0] = DP[3][0] = DP[4][0] = 1;
        for(int i = 1; i < n; i++) {
            DP[0][i] = ((DP[1][i - 1] + DP[2][i - 1]) % mod + DP[4][i - 1]) % mod;
            DP[1][i] = (DP[0][i - 1] + DP[2][i - 1]) % mod;
            DP[2][i] = (DP[1][i - 1] + DP[3][i - 1]) % mod;
            DP[3][i] = DP[2][i - 1];
            DP[4][i] = (DP[2][i - 1] + DP[3][i - 1]) % mod;
        }
        int ans = 0;
        for(int i = 0; i < 5; i++) {
            ans = (ans + DP[i][n - 1]) % mod; 
        }
        return ans;
    }
};