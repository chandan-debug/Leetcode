class Solution {
private:
    void solve(int ind, vector<int>& nums, vector<int>& ds, vector<vector<int>>& ans) {
        
        
        for (int i = ind; i < nums.size(); i++) {
            if (i != ind && nums[i] == nums[i - 1]) {
                continue;  // Skip duplicates
            }
            ds.push_back(nums[i]);
            solve(i + 1, nums, ds, ans);
            ds.pop_back();
        }
        ans.push_back(ds);  // Include the current subset
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(0, nums, ds, ans);
        return ans;
    }
};
