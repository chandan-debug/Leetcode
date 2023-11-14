class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,pair<int,int>> idx;
        for(char c : s) idx[c].first=idx[c].second=-1;
        for(int i = 0; i<s.length(); i++){
            if(idx[s[i]].first==-1){
                idx[s[i]].first=i;
            }
            else{
                idx[s[i]].second=i;
            }
        } 
        int ans = 0;
        for(char c : s){
            auto &entry = idx[c];
            if(entry.second==-1) continue;
            unordered_map<char,bool> occured;
            int j = entry.first+1;
            while(j<entry.second){
                if(!occured[s[j]]){
                    ans++;
                    occured[s[j]] = true;
                }
                j++;
            }
            entry.second=-1;
        }
        return ans;
    }
};