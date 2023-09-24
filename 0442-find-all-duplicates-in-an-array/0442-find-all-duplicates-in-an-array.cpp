class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (mp.find(nums[i]) != mp.end()) {
                ans.push_back(nums[i]);
            } else {
                mp[nums[i]] = 1; // Insert the number into the map with a count of 1.
            }
        }

        return ans;
    }
};
