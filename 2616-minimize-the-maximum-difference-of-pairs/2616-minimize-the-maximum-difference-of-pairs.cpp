class Solution {
public:
    
    bool helper(int mid, vector<int>& nums, int p){
        int ct = 0;
        // helper function counts how many pairs are possible with the following 'mid',
        for(int i = 1; i < nums.size(); i++){
            if(nums[i]-nums[i-1] <= mid){
                ct++;
                i++;
            }
        }
        // if count of pairs is more than 'p', then, the given mid can be a possible answer.
        return ct >= p;
    }
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int st = 0, end = 1e9, mid, res;
        while(st <= end){
            mid = st + (end-st)/2;
            //checking if 'mid' can be a possible answer.
            if(helper(mid, nums, p)){
                // if 'mid' can be a answer, store it and try to minimize if possible.
                res = mid;
                end = mid-1;
            }
            else st = mid+1;
        }
        return res;
    }
};