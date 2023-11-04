class Solution {
public:
    bool isPalindrome(string s) {
        // Clean the string by removing non-alphanumeric characters and converting to lowercase
        string ans;
        for (char c : s) {
            if (isalnum(c)) {
                ans += tolower(c);
            }
        }

        // Check if the cleaned string is a palindrome
        int left = 0;
        int right = ans.size() - 1;
        while (left < right) {
            if (ans[left] != ans[right]) {
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
