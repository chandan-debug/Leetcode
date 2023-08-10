class Solution {
public:
    bool check(vector<int> arr,int dif,int k)
    {
        int count = 1,first = arr[0];
        for(int i = 0;i<arr.size();i++)
        {
           if(arr[i]-first >=dif)
           {
               count++;
               first = arr[i];
           }
        }
        return count>=k;
    }
    int maximumTastiness(vector<int>& arr, int k) {

        sort(arr.begin(),arr.end());
        int n = arr.size();
        int left = 0,right = arr[n-1]-arr[0],ans = 0;
        if(k==1) return arr[n-1];

        while(left<=right)
        {
            int mid = (left+right)/2;
            if(check(arr,mid,k))
            {
                ans = mid;
                left = mid+1;
            }
            else
             right = mid-1;
        }
        return ans;  
    }
};