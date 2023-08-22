class Solution {
public:
    int reverse(int x) {
        long long reversed = 0; // Use a 64-bit integer
        
        while (x != 0) {
            int lastdigit = x % 10;
            reversed = reversed * 10 + lastdigit;
            x = x / 10;
        }
        
        // Check for overflow or underflow
        if (reversed > INT_MAX || reversed < INT_MIN) {
            return 0;
        }
        
        return static_cast<int>(reversed); // Convert back to 32-bit integer
    }
};
