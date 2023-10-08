class Solution {
    int solve(int i,int j,vector<vector<vector<int>>>&dp,vector<int>&a,vector<int>&b,int flag){
        if(i<0|| j<0){
            if(flag==1)
            return 0;

        // When we have not selected any element..
        // Beacuse we have to select atleast one pair
            return INT_MIN;
        }

        if(dp[i][j][flag]!=-1){
            return dp[i][j][flag];
        }
        int aa=a[i]*b[j]+solve(i-1,j-1,dp,a,b,1);
        int bb=solve(i-1,j,dp,a,b,flag);
        int cc=solve(i,j-1,dp,a,b,flag);
        int dd=solve(i-1,j-1,dp,a,b,flag);
        return dp[i][j][flag]=max(aa,max(bb,max(cc,dd)));
    }
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(2,-1)));
        return solve(n-1,m-1,dp,nums1,nums2,0);
    }
};