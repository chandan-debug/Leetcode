class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& A) {
         int n = A.size();
         sort(A.begin(),A.end());
         A[0] = 1;
            for(int i = 1;i<n;i++){
               if(A[i] - A[i-1] > 1){
                  A[i] = A[i-1] + 1;
               }
         }
         return A[n-1];
    }
};