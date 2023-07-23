class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
      vector<long long>nums2;
      for(auto &x:nums) nums2.push_back(x);
        
        for(int i=nums2.size()-1;i>0;i--){
            if(nums2[i-1]<=nums2[i]){
                nums2[i-1]=nums2[i-1]+nums2[i];
            }
        }
        return nums2[0];
    }
};