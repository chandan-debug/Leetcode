class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            if(!dq.empty() && dq.front()==i-k)  //out of bound
                dq.pop_front();
           while(!dq.empty() && nums[dq.back()] < nums[i]){  //check decreasing fashion 
                dq.pop_back();
           }
                dq.push_back(i);
            
            if(i>=k-1)  // indx =0,1,2  and k=3
              ans.push_back(nums[dq.front()]);
        }
        return ans;
        
    }
};