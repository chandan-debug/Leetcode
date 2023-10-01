

class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string result = "";
        
        for (char c : s) {
            if (c != ' ') {
               st.push(c);
            } else {
                while (!st.empty()) {
                    result += st.top();
                    st.pop();
                }
                result += ' '; // Add space after each word
            }
        }
        
        while (!st.empty()) {
            result += st.top();
            st.pop();
        }
        
        return result;
    }
};
