
class Solution {
public:
    bool isPalindrome(int x) {
        //If we have negative numbers ?
        //If we have zero at end and it is not zero ?
        if(x<0 || (x%10==0 && x!=0)){
            return false;
        }
        //Do we have constraint of INT_MAX and INT_MIN?
        int num=x;
        long rev=0;
        while(x!=0){
            int rem=x%10;
            x=x/10;
            rev=rev*10+rem;
        }
        cout<<rev;
        return rev==num;
    }
};