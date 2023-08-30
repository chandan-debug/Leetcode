class Solution {
public:
    bool isSafe(vector<vector<int>>& grid,int n, int m, int i,int j){
        
        return(i>=0 && i<n && j>=0 && j<m &&grid[i][j]==1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int timer=-1;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=3;
                }
            }
        }
        int n=grid.size();
        int m=grid[0].size();
        
        while(!q.empty()){
            int count=q.size();
            for(int k=0;k<count;k++){
                auto index=q.front();
                int i=index.first;
                int j=index.second;
                
                if(isSafe(grid,n,m,i,j+1)){
                    q.push({i,j+1});
                    grid[i][j+1]=3;
                }
                 if(isSafe(grid,n,m,i,j-1)){
                    q.push({i,j-1});
                    grid[i][j-1]=3;
                }
                 if(isSafe(grid,n,m,i+1,j)){
                    q.push({i+1,j});
                    grid[i+1][j]=3;
                }
                 if(isSafe(grid,n,m,i-1,j)){
                    q.push({i-1,j});
                    grid[i-1][j]=3;
                }
                q.pop();
              
                
            }
             timer++;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        return max(0,timer);
    }
};