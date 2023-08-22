class Solution {
public:
    
    string convertToTitle(int columnNumber) {
    string ans = "";  // This will store the final column title
    
    while(columnNumber) {
        columnNumber--;  // Decrementing by 1 since column titles start from 'A' (1) instead of 'A' (0)

        // Extracting the last character and appending it to the string
        ans += 'A' + columnNumber % 26;  // This calculates the corresponding character for the current digit
        columnNumber /= 26;  // Move to the next digit
    }

    // Reversing because characters were appended in reverse order
    reverse(ans.begin(), ans.end());
    return ans;


    }
};