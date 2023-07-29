class Solution {
public:
    
    double takesoup(int a, int b,vector<vector<double>>& dp){
        if(a<=0 && b>0) return 1.0;
        if(a<=0 && b<=0) return 0.5;
        if(a>0 && b<=0) return 0.0;

        if(dp[a][b] != -1) return dp[a][b];

        return dp[a][b] = 0.25*(takesoup(a-100,b,dp) + takesoup(a-75,b-25,dp) + takesoup(a-50,b-50,dp) + takesoup(a-25,b-75,dp));
    }
    double soupServings(int n) {
        if(n >= 5000) return 1.0;
        vector<vector<double>> dp(n+1,vector<double>(n+1,-1));
        return takesoup(n,n,dp);
    }
};