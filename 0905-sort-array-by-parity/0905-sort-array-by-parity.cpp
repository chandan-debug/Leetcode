class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int j=0;
        int k=nums.size()-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                ans[j]=nums[i];
                j++;
            }
            else{
                ans[k]=nums[i];
                k--;
            }
        }
        
        return ans;
    }
};