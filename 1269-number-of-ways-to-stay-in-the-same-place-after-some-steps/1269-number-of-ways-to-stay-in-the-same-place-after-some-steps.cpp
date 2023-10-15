class Solution {
public:
    int dp[501][501];
    const int MOD=1e9+7;
    int f(int steps,int arrLen,int i,int c){
        if(i<0 || i>=arrLen){
            return 0;
        }
        if(dp[i][c]!=-1){
            return dp[i][c];
        }
        if(c==steps){
            if(i==0){
                return 1;
            }
            return 0;
        }
        
        

        int ans=f(steps,arrLen,i,c+1);
        int ans2=f(steps,arrLen,i+1,c+1)+f(steps,arrLen,i-1,c+1);
        return dp[i][c]=(ans%MOD+ans2%MOD)%MOD;
    }
    int numWays(int steps, int arrLen) {
        memset(dp,-1,sizeof(dp));
        return f(steps,arrLen,0,0);
    }
};