class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        
        string word="";
        for(int i=0;i<s.size();i++){
            if(s[i]!=' '){
                while(s[i]!=' ' &&  i<s.size()){
                    word+=s[i];
                    i++;
                }
                st.push(word);
                word="";
            }
        }
        
        string reverse;
        while(!st.empty()){
            reverse+=st.top();
            st.pop();
            if(!st.empty()){
                reverse+=" ";
            }
        }
        
        return reverse;
    }
};