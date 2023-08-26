class Solution {
public:
    void helper(string digits,int i,string cur,vector<string> &ans,unordered_map<char,string> &m)
    {
        if(i == digits.size())
        {
            ans.push_back(cur);
            return;
        }

        for(int j=0;j<m[digits[i]].size();j++)
        {
            string key = m[digits[i]];
            helper(digits,i+1,cur + key[j],ans,m);
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        if(digits.size() == 0)
            return {};

        unordered_map<char,string> m = {{'2',"abc"},
        {'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},
        {'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"}};

        string cur = "";
        vector<string> ans;

        helper(digits,0,cur,ans,m);
        return ans;
    }
};