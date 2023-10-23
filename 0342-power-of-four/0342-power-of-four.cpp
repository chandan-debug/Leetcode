class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n==0){
            return false;
        }
       double po = log(n) / log(4);
       if(po==floor(po)){
           return true;
       } 
       return false;
    }
};