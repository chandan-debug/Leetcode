class Solution {
public:
    int solve(int amount,int ind,vector<int>&coins,vector<vector<int>>& dp){
        
        if(amount == 0)return 1;
        
        if(ind < 0 || amount < 0)return 0;
        
        if(dp[ind][amount] != -1) 
            return dp[ind][amount];
        
        int pick = solve(amount - coins[ind],ind,coins,dp);
        int notpick = solve(amount,ind-1,coins,dp);

        return dp[ind][amount] = pick + notpick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
       vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return solve(amount,n-1,coins,dp);
    }
};