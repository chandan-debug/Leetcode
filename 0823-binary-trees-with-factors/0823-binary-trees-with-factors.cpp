class Solution {
 public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        long long ans = 0;
        int n=arr.size(),MOD = 1e9+7;
        unordered_map<int,long long>dp;

        for(int i=0; i<n; i++){
            dp[arr[i]]=1;
            for(int j=0; j<i; j++){
                if(arr[i]%arr[j]==0){
                    int division = arr[i]/arr[j];
                    if(dp.count(division)){
                        dp[arr[i]]=(dp[arr[i]]+dp[arr[j]]*dp[division])%MOD;
                    }
                }
            }
            ans = (ans+dp[arr[i]])%MOD;
        }

        return ans;
    }
};