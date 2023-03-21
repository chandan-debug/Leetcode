class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int ans=0, count=0;
        
        for(int x:nums){
            if(x){
                count=0;
            }
            else{
                count++;
                    ans+=count;
            }
        }
        return ans;
    }
};