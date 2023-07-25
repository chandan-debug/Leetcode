// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& arr) {
//         int largestelement=INT_MIN;
//         int ans=-1;
//         for(int i=0;i<arr.size();i++){
//             if(arr[i]>largestelement){
//                 ans=i;
//                 largestelement=arr[i];
//             }
//         }
//         return ans;
        
//     } TC=O(arr.size())
//Sc=O(1)
// };


class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int left=0;
        int right=arr.size()-1;
        
        while(left<right){
            int mid=left+(right-left)/2;
            
            if(arr[mid]<arr[mid+1]){
                left=mid+1;
            }
            else{
                right=mid;
            }
        }
        return left;
        
        
    }
};