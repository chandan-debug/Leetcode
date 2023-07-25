class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int largestelement=INT_MIN;
        int ans=-1;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>largestelement){
                ans=i;
                largestelement=arr[i];
            }
        }
        return ans;
        
    }
};