class Solution {
public:
    int minPairSum(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end()) ;
        int n = nums.size() ;
        int s = 0 ;
        int e = n-1 ;
        int ans = 0 ;

        while(s < e)
            ans = max(ans, ( nums[s++] + nums[e--] )) ;
            
        return ans ;
    }
};