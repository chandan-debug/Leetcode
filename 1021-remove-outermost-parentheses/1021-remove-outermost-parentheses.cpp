class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count{0};
        for(char c:s){
            if(c == '(' and count == 0){
                count++;
            }
            else if(c == '(' and count>=1){
               res+=c;
               count++;
            }
            else if(c == ')' and count>1){
                res+=c;
                count--;
            }
            else if(c == ')' and count == 1){
                count--;
            }
         }
        return res;

        
    }
};