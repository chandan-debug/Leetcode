class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        
        vector<vector<int>> ans;
        
        for(int i=0;i<n;i++){
            if(ans.empty()){
                ans.push_back(intervals[i]);
            }
            else{
                vector<int>&v=ans.back();
                //end of previous interval comapre with i's start
                int y=v[1];
            //if overlap
                
            if(intervals[i][0]<=y){
                v[1]=max(y,intervals[i][1]);
            }
                //not overlap
                
            else{
                ans.push_back(intervals[i]);
            }
        }
        }
        return ans;
    }
};