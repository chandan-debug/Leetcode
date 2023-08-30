class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
         
         int n = nums.size();
         int prev = nums[n-1];

         long long ans = 0;

         for(int i = n-1;i>0;i--){

             // If both value already sorted nothing to do only prev will change 
             if(nums[i-1]<=prev){
                 prev = nums[i-1];
                 continue;
             }
             // If not sorted 
             if(nums[i-1]>prev){
                  
                  long long inc = ceil(nums[i-1] / (double)(prev));
                  ans += inc-1;
                  //update prev for next turn 
                  prev = nums[i-1]/inc;
             }
         }

         return ans;
    }
};