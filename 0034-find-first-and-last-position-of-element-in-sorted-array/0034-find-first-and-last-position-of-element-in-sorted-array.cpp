class Solution {
public:
    int firstsearch(vector<int>& nums, int target,int l ,int h){
        int start=-1;
        
        while(l<=h){
            int mid=(l+h)>>1;
            
            if(nums[mid]==target){
                start=mid;
                h=mid-1;
            }
             if(target>nums[mid]){
                l=mid+1;
            }
            if(target<nums[mid]){
                h=mid-1;
            }
        }
        return start;
    }
      int lastsearch(vector<int>& nums, int target,int l ,int h){
        int end=-1;
        
        while(l<=h){
            int mid=(l+h)>>1;
            
            if(nums[mid]==target){
                end=mid;
                l=mid+1;
            }
             if(target>nums[mid]){
                l=mid+1;
            }
            if(target<nums[mid]){
                h=mid-1;}
        }
        return end;
        
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int start=firstsearch(nums,target,0,nums.size()-1);
        int end=lastsearch(nums,target,0,nums.size()-1);
        
        return{start,end};
        
        
    }
};