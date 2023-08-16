//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans;
        deque<int> dq;  // Using a deque to store indices of elements
        
        for (int i = 0; i < n; i++) {
            // Remove elements that are out of the current window
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();
            
            // Remove smaller elements from the back as they are not useful anymore
            while (!dq.empty() && arr[dq.back()] < arr[i])
                dq.pop_back();
            
            dq.push_back(i); // Add the current index to the deque
            
            // Once the window size becomes 'k', start adding maximums to 'ans'
            if (i >= k - 1)
                ans.push_back(arr[dq.front()]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends