class Solution {
private:
void solve(vector<int> nums, vector<int> output, int i,vector<vector<int>>& ans){

//basecase

if(i>=nums.size()){
ans.push_back(output);
return;}

//exclude
solve(nums,output,i+1,ans);

//include

output.push_back(nums[i]);
solve(nums,output,i+1,ans);
} 

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        solve(nums,output,0,ans);
        return ans;
    }
};