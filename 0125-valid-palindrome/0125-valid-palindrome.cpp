class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from the left
            while (left < right && !isalnum(s[left]))
                left++;
            
            // Skip non-alphanumeric characters from the right
            while (left < right && !isalnum(s[right]))
                right--;
            
            // Convert both characters to lowercase and compare
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            
            // Move the pointers towards each other
            left++;
            right--;
        }
        
        return true;
    }
};
