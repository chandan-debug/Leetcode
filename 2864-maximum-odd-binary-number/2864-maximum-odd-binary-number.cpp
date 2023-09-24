class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int cnt=0;
        for(auto i:s){
            if(i=='1'){
                cnt++;
            }
        }
        
        string ans="";
        for(int i=0;i<s.size()-1;i++){
            if(i<cnt-1)
                ans+="1";
            else
                ans+="0";
        }
        ans+="1";
        return ans;
        
    }
};