class Solution {
public:
    bool isPalindrome(string s) {
        int left=0;
        int right=s.size()-1;
        
        while(left<right){
            // skip the non alaphabet from left side
            while(left<right && !isalnum(s[left]))
                left++;
            
             // skip the non alaphabet from right side
            while(left<right && !isalnum(s[right]))
                right--;
            
            //convert the char to lower case and compare 
            
            if(tolower(s[left])!=tolower(s[right]))
                return false;
            
            left++;
            right--;
        }
        return true;
    }
};