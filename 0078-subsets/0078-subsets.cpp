class Solution {
private:
void solve(vector<int> nums, vector<int> ds, int i,vector<vector<int>>& ans){

//basecase

if(i==nums.size()){
ans.push_back(ds);
return;}

//exclude
solve(nums,ds,i+1,ans);

//include

ds.push_back(nums[i]);
solve(nums,ds,i+1,ans);
    ds.pop_back();
} 

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(nums,ds,0,ans);
        return ans;
    }
};