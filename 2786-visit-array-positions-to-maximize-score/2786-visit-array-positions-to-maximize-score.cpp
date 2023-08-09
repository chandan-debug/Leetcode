class Solution {
public:
    long long helper(vector<int>&nums,int x,int oe,int index,vector<vector<long long>> &dp){
        if(nums.size()==index) return 0;
        if(dp[index][oe]!=-1) return dp[index][oe];
        long long pick=0,notpick=0;
        if(oe==nums[index]%2){
            pick=nums[index]+helper(nums,x,oe,index+1,dp);
        }
        else{
            pick=nums[index]-x+helper(nums,x,nums[index]%2,index+1,dp);
        }
        notpick=helper(nums,x,oe,index+1,dp);
        return dp[index][oe]=max(pick,notpick);
        
    }
    long long maxScore(vector<int>& nums, int x) {
        vector<vector<long long>> dp(nums.size(),vector<long long>(2,-1));
        int oe;
        oe=nums[0]%2==0?0:1;
        return helper(nums,x,oe,0,dp);
    }
};