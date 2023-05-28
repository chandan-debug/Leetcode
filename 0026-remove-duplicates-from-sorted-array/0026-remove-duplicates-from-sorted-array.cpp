class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    unordered_set<int> st;
    int n = nums.size();
    int count = 0;  // Count of unique elements

    for (int i = 0; i < n; i++) {
        if (st.count(nums[i]) == 0) {
            st.insert(nums[i]);
            nums[count] = nums[i];  // Overwrite the element at the count position
            count++;
        }
    }

    return count;
}
};