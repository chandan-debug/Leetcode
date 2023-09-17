class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int n = graph.size();
        int dp[1<<n][n];
        for (int i=0; i< (1<<n); i++)
            for (int j=0; j<n; j++)
                dp[i][j] = INT_MAX; 
        vector<pair<int, int>> updated;
        
        vector<pair<int, int>> new_updated;
        for (int i=0; i<n; i++){
            dp[1<<i][i] = 0;
            updated.push_back(pair<int, int>(1<<i, i));
        }
        while (!updated.empty()){
            for (int i=0; i< updated.size(); i++){
                int curr = updated[i].second;
                int covered = updated[i].first;
                for (int j=0; j<graph[curr].size(); j++){
                    int next = graph[curr][j];
                    int new_covered = covered;
                    if (((covered & (1<<next))==0))
                        new_covered += (1<<next);
                    if ( dp[new_covered][next] <= dp[covered][curr] + 1)
                        continue;
                    dp[new_covered][next] = dp[covered][curr] + 1;
                    new_updated.push_back(pair<int, int>(new_covered, next));
                    //cout<<"Update "<<bitset<sizeof(int) * 8>(new_covered)<<" "<<next<<" "<<dp[new_covered][next]<<endl;
                }
            }
            updated = new_updated;
            new_updated.clear();
            
        }
        int ret = INT_MAX;
            for (int i=0; i<n; i++) 
                ret = min(ret, dp[(1<<n) - 1][i]);
            return ret;
    }
};