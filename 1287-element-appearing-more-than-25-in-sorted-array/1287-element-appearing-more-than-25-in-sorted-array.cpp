class Solution {
public:
    int findSpecialInteger(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int cnt = 1;

        int per = n / 4;

        for(int i=1;i<n;i++){
            if(nums[i] == prev)
                cnt++;
            else
                cnt = 1;
                
            if(cnt > per) return nums[i];
            
            prev = nums[i];
        }

        return nums[n-1];
    }
};