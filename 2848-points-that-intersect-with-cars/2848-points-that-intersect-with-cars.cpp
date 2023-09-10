class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        
        sort(nums.begin(),nums.end());
        for(int i =0;i<n;i++)
        {
            if(ans.size()==0 || ans.back()[1]<nums[i][0])
            {
                ans.push_back(nums[i]);
            }
            else
            {
                ans.back()[1]=max(ans.back()[1],nums[i][1]);
                   
            }
        }
        int count = 0;
        for(int i =0;i<ans.size();i++)
        {
            count = count + (ans[i][1] - ans[i][0] + 1);
            
        }
        return count;
        
        
    }
};