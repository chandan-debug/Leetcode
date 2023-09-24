class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (st.empty()) {
                st.push(c);
            } else if ((st.top() == '(' && c == ')') || (st.top() == '{' && c == '}') || (st.top() == '[' && c == ']')) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        
        if (st.empty()) {
            return true;
        }
        
        return false;
    }
};