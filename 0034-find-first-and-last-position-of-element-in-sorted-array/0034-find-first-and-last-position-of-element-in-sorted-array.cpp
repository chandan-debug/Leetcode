class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int startingPosition = findStartingPosition(nums, target, 0, n - 1);
        int endingPosition = findEndingPosition(nums, target, 0, n - 1);
        return {startingPosition, endingPosition};
    }
    
private:
    int findStartingPosition(vector<int>& nums, int target, int left, int right) {
        int startingPosition = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
            if (nums[mid] == target) {
                startingPosition = mid;
            }
        }
        return startingPosition;
    }
    
    int findEndingPosition(vector<int>& nums, int target, int left, int right) {
        int endingPosition = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] <= target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
            if (nums[mid] == target) {
                endingPosition = mid;
            }
        }
        return endingPosition;
    }
};
