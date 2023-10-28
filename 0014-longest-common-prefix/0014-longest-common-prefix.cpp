class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return " ";
        }
        
        sort(strs.begin(),strs.end());
        string first=strs[0];
       string  last=strs[strs.size()-1];
        string ans="";
        
        for(int i=0;i<first.size();i++){
            if(first[i]!=last[i]){
                break;
            }
            else{
                ans.push_back(first[i]);
            }
        }
        return ans;
    }
};