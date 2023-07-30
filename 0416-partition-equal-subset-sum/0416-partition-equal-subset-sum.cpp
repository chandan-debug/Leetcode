class Solution {
public:
    int solve(int i,vector<int>&nums, int target,vector<vector<int>>&dp){
        if(i>=nums.size())
            return 0;
        if(target<0)
            return 0;
        if(target==0)
            return 1;
        if(dp[i][target]!=-1){
            return dp[i][target];
        }
        
        bool  inc=solve(i+1,nums,target-nums[i],dp);
        bool exc=solve(i+1,nums,target-0,dp);
        return dp[i][target]=inc || exc;
    }
    
    bool canPartition(vector<int>& nums) {
        
        int total=0;
        for(int i=0;i<nums.size();i++){
            total+=nums[i];
        }
        if(total & 1)
            return 0;
        
        int target=total/2;
        vector<vector<int>> dp(nums.size(),vector<int>(target+1,-1));
        
      return  solve(0,nums,target,dp);
        
    }
};