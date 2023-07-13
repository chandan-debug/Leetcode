class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> graph[n];
        vector<int> indegree(n,0);
        
        for(int i=0;i<pre.size();i++){
            int u=pre[i][0], v=pre[i][1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        
        queue<int> q;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        
        int c=0;
        while(q.size()>0){
            int u=q.front();
            q.pop();
            
            c++;
            
            for(int i=0;i<graph[u].size();i++){
                int v=graph[u][i];
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                }
            }
        }
        return (c==n);
    }
};