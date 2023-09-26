class Solution {
public:
    string removeDuplicateLetters(string s) {
        stack<char> st;
        map<char, int> mp;
        vector<bool> visited(26, false);

        // Frequency calculation
        for (char c : s) {
            mp[c]++;
        }

        for (char c : s) {
            mp[c]--;

            if (!visited[c - 'a']) {
                while (!st.empty() && st.top() > c && mp[st.top()] > 0) {
                    visited[st.top() - 'a'] = false;  // Mark unvisited
                    st.pop();
                }

                st.push(c);
                visited[c - 'a'] = true;  // Mark visited
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
