class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(int i=0;i<numRows;i++){
            // side are always 1
            vector<int> v(i+1,1);
            for(int j=1;j<i;j++){
                
                // current->i  previous->i-1
                v[j]=ans[i-1][j]+ans[i-1][j-1];
            }
            ans.push_back(v);
        }
        return ans;
        
    }
};