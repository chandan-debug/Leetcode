class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        //finding root using indegree concept i.e. if indegree is zero then root and if more than one root return false;
        vector<int> indegree(n,0);
        for(int i=0;i<n;i++){
            if(leftChild[i] != -1) indegree[leftChild[i]]++;
            if(rightChild[i] != -1) indegree[rightChild[i]]++;
        }

        //adding root to  queue
        queue<int> q;
        vector<bool> vis(n,false);

        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                 q.push(i);
                 vis[i] = true;
            }
        }

        if(q.size() > 1) return false; //can not be more than one root

        //solve for rest nodes
        int cntNodes = 0; //to ensure all nodes are visited

        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            cntNodes++;

            if(leftChild[node] != -1){
                if(vis[leftChild[node]]) return false;
                vis[leftChild[node]] = true;
                q.push(leftChild[node]);
            }

            if(rightChild[node] != -1){
                if(vis[rightChild[node]]) return false;
                vis[rightChild[node]] = true;
                q.push(rightChild[node]);
            }
        }

        return cntNodes == n;
    }
};