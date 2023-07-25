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
                 // We are on the ascending part of the mountain.
                // Move left pointer to mid + 1.
                left=mid+1;
            }
            else{
                 // We are on the descending part of the mountain.
                // Move right pointer to mid.
                right=mid;
            }
        }
        // At the end of the loop, left == right, and it will be pointing to the peak element.
        return left; // or right (they both have the same value)
        
        //TC: O(log N)
       //SC: O(1)
    }
};