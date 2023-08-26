bool cmp(vector<int>& a, vector<int>& b){
    if(a[0]==b[0]) return a[1]<b[1];
    return a[0]<b[0];
}
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        if(n==1) return 1;
        sort(pairs.begin(),pairs.end(),cmp);
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};