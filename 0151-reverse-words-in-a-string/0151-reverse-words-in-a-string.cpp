class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ') {
                while (s[i] != ' ' && i < s.size()) {
                    word += s[i];
                    i++;
                }
                st.push(word);
                word = "";
            }
        }
        
        string reversed;
        while (!st.empty()) {
            reversed += st.top();
            st.pop();
            if (!st.empty()) {
                reversed += " ";
            }
        }
        
        return reversed;
    }
};