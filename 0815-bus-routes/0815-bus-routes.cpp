class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
        int n=routes.size();
        unordered_map<int,vector<int>>mp;
        unordered_set<int>st;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int&x:routes[i]){
                mp[x].push_back(i);
            }
        }
        q.push({S,0});
        st.insert(S);
        while(!q.empty()){
            int bus=q.front().second,stop=q.front().first;q.pop();
            if(stop==T) return bus;
            for(int&busNo:mp[stop]){
                for(int&node:routes[busNo]){
                    if(st.find(node)==st.end()){
                        st.insert(node);
                        q.push({node,bus+1});
                    }
                }
                routes[busNo].clear();
            }
        }
        return -1;
    }
};