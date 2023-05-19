class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int infpt=0;
        
        for(int i=n-1; i>0;i--){
            if(nums[i]>nums[i-1]){
                infpt=i;
                break;
            }
        }
        if(infpt==0){
            sort(nums.begin(),nums.end());
        }
        
        else{
            int min=INT_MAX;
            int swap=nums[infpt-1];
            
            for(int j=infpt;j<n;j++){
                if(nums[j]-swap>0 && nums[j]-swap<min){
                    int temp=nums[j];
                    nums[j]=nums[infpt-1];
                    nums[infpt-1]=temp;
                }
            }
            sort(nums.begin()+infpt,nums.end());
        }
    }
};