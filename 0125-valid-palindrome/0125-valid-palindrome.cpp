class Solution {
public:
    bool isPalindrome(string s) {
        string ans;
        for(auto c:s){
            if(isalnum(c)){
                ans+=tolower(c);
            }
        }
            int left=0;
            int right=ans.size()-1;
            
            while(left<right){
                if(ans[left]!=ans[right]){
                    return false;
                }
                left++;
                right--;
            }
            return true;  
        }
      
};