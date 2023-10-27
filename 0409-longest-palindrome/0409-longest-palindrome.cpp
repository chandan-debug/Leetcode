class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> mp;
        
        for(char c:s){
            mp[c]++;
            
        }
        int len=0;
        bool odd=false;
        
        for(const auto& x:mp){
            int cnt=x.second;
            
            if(cnt%2==0){
                len+=cnt;
            }
            else{
                len+=cnt-1;
                odd=true;
            }
        }
        
        if(odd){
            len++;
        }
        return len;
    }
};