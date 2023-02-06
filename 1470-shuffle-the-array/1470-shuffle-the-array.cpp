class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> res;
        for(int i=0,index = 0; index < 2*n; i++){
            res.push_back(nums[i]);
            index++;
            
             res.push_back(nums[i+n]);
            index++;
        }
        return res;
    }
};