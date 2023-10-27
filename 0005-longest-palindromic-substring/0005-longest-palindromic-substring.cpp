class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 1;
        
        for (int i = 1; i < s.size(); i++) {
            int left = i - 1, right = i;
            
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                int curLen = right - left + 1;
                if (curLen > maxLen) {
                    maxLen = curLen;
                    start = left;
                }
                
                left--;
                right++;
            }
            
            left = i - 1, right = i + 1;
            while (left >= 0 && right < s.size() && s[left] == s[right]) {
                int curLen = right - left + 1;
                if (curLen > maxLen) {
                    maxLen = curLen;
                    start = left;
                }
                
                left--;
                right++;
            }
        }
        
        return s.substr(start, maxLen);
    }
};