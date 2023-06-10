class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        
        vector<int> count(26, 0); // Character count array
        
        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++; // Increment count for characters in s
            count[t[i] - 'a']--; // Decrement count for characters in t
        }
        
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false; // If any count is non-zero, strings are not anagrams
            }
        }
        
        return true; // All counts are zero, strings are anagrams
    }
};
