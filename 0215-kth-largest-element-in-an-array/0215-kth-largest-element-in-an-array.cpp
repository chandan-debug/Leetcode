class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;  //Priority queue (min heap)
        for(auto x: nums){
            pq.push(x);   // Push all elements in pq.
            if(pq.size()>k){  // If size(pq)>k , pop the top element.
                pq.pop();
            }
        }
        return pq.top();  // Kth largest element
    }
};
