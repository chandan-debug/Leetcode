class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> frequency;
        
        // Count the frequency of each character in the string.
        for (char c : s) {
            frequency[c]++;
        }
        
        int length = 0;
        bool hasOddFrequency = false;

        // Iterate through the frequency map.
        for (const auto& pair : frequency) {
            int count = pair.second;
            
            // If the frequency is even, we can use all of them in the palindrome.
            if (count % 2 == 0) {
                length += count;
            } else {
                // If the frequency is odd, we can use all even occurrences and one odd occurrence.
                length += count - 1;
                hasOddFrequency = true;
            }
        }
        
        // If there was at least one character with an odd frequency, add 1 to the length.
        if (hasOddFrequency) {
            length++;
        }
        
        return length;
    }
};
