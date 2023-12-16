class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        
        vector<int> count(256,0);
        for(char c:s){
            count[c]++;
        }
        
        for(char c:t){
            if(count[c]==0)
                return false;
            count[c]--;
        }
        return true;
    }
};