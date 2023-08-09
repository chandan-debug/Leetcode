class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;
        
        while (left < right) {
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
            left++;
            right--;
        }
    }
};
// In this code, we're using a two-pointer approach to swap characters from the left and right ends of the vector until they meet in the middle, effectively reversing the string in-place.





