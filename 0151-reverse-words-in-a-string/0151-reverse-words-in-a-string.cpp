
class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                if (!word.empty()) {
                    st.push(word);
                    word = "";
                }
            } else {
                word += s[i];
            }
        }
        if (!word.empty()) {
            st.push(word);
        }

        vector<string> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        string reversed;
        for (int i = 0; i < ans.size(); i++) {
            reversed += ans[i];
            if (i < ans.size() - 1) {
                reversed += " ";
            }
        }

        return reversed;
    }
};