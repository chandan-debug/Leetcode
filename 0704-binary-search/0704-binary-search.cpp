class Solution {
public:
   int search(vector<int>& arr,int s,int e, int key){
    //basecase
    //elemnt not found
        if(s>e){
            return -1;
        }
        int mid=(s+e)>>1;
    //element found
        if(arr[mid]==key){
            return mid;
        }

        if(arr[mid]<key){
            return search(arr,mid+1,e,key);
        }
        else{
            return search(arr,s,mid-1,key);
        }
}
    int search(vector<int>& nums, int target) {
        return search(nums,0,nums.size()-1,target);
    }
};


 

