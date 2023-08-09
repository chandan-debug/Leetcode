class Solution {
public:
    int solve(int i,int &n,string &str,unordered_set<string> &s,vector<int> &dp){
        if(i>=n)return 0;
        if(dp[i] != -1)return dp[i];
        int a = 1+solve(i+1,n,str,s,dp);
        string s1 = "";
        for(int j = i; j < n; j++){
            s1 += str[j];
            if(s.count(s1)){
                a = min(a,solve(j+1,n,str,s,dp));
            }
        }
        return dp[i] = a;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length();
        vector<int> dp(n,-1);
        unordered_set<string> st;
        for(auto &i: dictionary){
            st.insert(i);
        }
        return solve(0,n,s,st,dp);
    }
};