class Solution {
public:
//using binary search and sliding window approach
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int l=1, h=n;
        int ans=0;
        sort(nums.begin(), nums.end());
        while(l<=h)
        {
            int mid= l+(h-l)/2;
            if(isPossible(mid,nums,k))
            {
                ans=mid;
                l=mid+1;
            }
            else
            h=mid-1;
        }
        return ans;
    }
    bool isPossible(int mid, vector<int> &nums, int k)
    {
        int n=nums.size();
        long long int windowsum=0, totalsum=0;
        for(int i=0;i<mid;i++)
        
            windowsum+= nums[i];
            totalsum= 1LL*nums[mid-1]*mid;
            if(totalsum-windowsum<=k)
            return 1;

            int j=0;
            for(int i=mid;i<n;i++)
            {
                windowsum-=nums[j];
                windowsum+=nums[i];
                totalsum = 1LL * nums[i] * mid;
                  if(totalsum-windowsum<=k)
            return 1;
            j++;

            }
            return 0;
        
    }
};