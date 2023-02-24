class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int mini=INT_MAX;
        int diff=INT_MAX;
        
        for(auto x:nums){
            if(x%2==1){
                x=x*2;
            }
            mini=min(mini,x);
            pq.push(x);
        }
        while(pq.top()%2==0){
            int max=pq.top();
            pq.pop();
            diff=min(diff,max-mini);
            mini=min(mini,max/2);
            pq.push(max/2);
            
        }
        return min(diff,pq.top()-mini);
    }
};