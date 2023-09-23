class Solution {
private:
    bool isValid(string s1,string s2){
        if(s1.length() +1 != s2.length()) return false;
        int i=s1.length()-1;
        int j=s2.length()-1;
        while(i>=0 && j>=0){
            if(s1[i]==s2[j]){
                i--;
            }
            j--;
        }
        return i==-1;
    }
    static bool cmp(string a ,string b){
        return a.length()<b.length();
    }
public:
    int solve(int index,int prev,vector<string> &words,vector<vector<int>> &dp){
        //base case
        if(index>=words.size()) return 0;
        if(dp[index][prev+1] !=-1 ){
            return dp[index][prev+1];
        }

        int take=0;
        if(prev==-1 || isValid(words[prev],words[index])){
            take = 1+solve(index+1,index,words,dp);
        }
        int notTake=solve(index+1,prev,words,dp);
        return dp[index][prev+1] = max(take,notTake);
    }

    int solveTab(vector<string> &words){
         int n=words.size();
         vector<vector<int>> dp(n+1,vector<int>(n+2,0));

         for(int index=n-1;index>=0;index--){
             for(int prev=index-1;prev>=-1;prev--){
                int take=0;
                if(prev==-1 || isValid(words[prev],words[index])){
                    take = 1+dp[index+1][index+1];
                }
                int notTake= dp[index+1][prev+1];
                dp[index][prev+1] = max(take,notTake);
             }
         }
         return dp[0][0];
    }

    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(),words.end(),cmp);

        // for(auto word: words) cout<<word<<' ';
        // vector<vector<int>> dp(n+1,vector<int>(n+2,-1));
        // return solve(0,-1,words,dp);
        return solveTab(words);
    }
};