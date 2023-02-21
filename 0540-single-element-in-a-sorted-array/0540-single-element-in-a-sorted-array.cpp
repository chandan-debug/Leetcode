class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int mid;
        
        //  boundary cases
        if(e==0){
            return nums[0];
        }
        else if(nums[0]!=nums[1]){
            return nums[0]; 
        }
        else if(nums[e]!=nums[e-1]){
            return nums[e];
        }
        
        while(s<=e){
            mid=s+(e-s)/2;
            //unique element condition
            if(nums[mid]!=nums[mid+1] && nums[mid]!=nums[mid-1]){
                return nums[mid];
            }
            if(((mid%2)==0 && nums[mid]==nums[mid+1]) || ((mid%2)==1 && nums[mid]==nums[mid-1])){
                s=mid+1;
            }
            else{
                e=mid-1;
            }
        }
        return s;
    }
};