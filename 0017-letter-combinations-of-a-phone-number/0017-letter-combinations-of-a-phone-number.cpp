class Solution {
    private:
    
    void solve(int i, string digits, string ds,vector<string>&ans, string map[]){
        //base case
        if(i>=digits.size()){
            ans.push_back(ds);
            return;
        }
        int number=digits[i]-'0';
        string value=map[number];
        
        for(int j=0;j<value.size();j++){
            ds.push_back(value[j]);
            solve(i+1,digits,ds,ans,map);
            ds.pop_back();
        }
        
    }
public:
    vector<string> letterCombinations(string digits) {
     vector<string> ans;
        if(digits.size()==0){
            return ans;
        }
        string ds;
        string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        solve(0,digits,ds,ans,map);
        return ans;
            
    }
};