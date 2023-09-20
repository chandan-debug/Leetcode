class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int start = 0, end = 0;
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        int sumToTake = totalSum - x;
        
        if (totalSum == x) {
            return nums.size(); // If the total sum equals x, return the size of the array.
        }
        
        if (sumToTake < 0) {
            return -1; // If it's impossible to achieve x, return -1.
        }
        
        int ans = -1; // Initialize ans to -1.
        int sum = 0;
        
        while (end < nums.size()) {
            sum += nums[end];
            
            while (sum > sumToTake) {
                sum -= nums[start++];
            }
            
            if (sum == sumToTake) {
                ans = max(ans, end - start + 1);
            }
            
            end++;
        }
        
        return ans == -1 ? -1 : nums.size() - ans;
    }
};
