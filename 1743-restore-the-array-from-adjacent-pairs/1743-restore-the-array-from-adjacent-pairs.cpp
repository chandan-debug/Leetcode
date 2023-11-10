class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
       map<int,vector<int>>mp;
       for(auto x : adjacentPairs)
       {
           mp[x[0]].push_back(x[1]);
           mp[x[1]].push_back(x[0]);
       }

       int head=0;
       for(auto x : mp)
       {
           if(x.second.size()==1)
           {
               head=x.first;
               break;
           }
       }

      map<int,int>vis;
      vector<int>res;
       queue<int>q;
       q.push(head);
       vis[head]=1;
    

       while(!q.empty())
       {
           int u = q.front();
           q.pop();
            res.push_back(u);
           for(auto x : mp[u])
           {
               if(vis[x]==false)
               {
                   q.push(x);
                   vis[x]=1;
                  
               }
           }
       }
       return res;
    }
};