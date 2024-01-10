/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> adj[110000];
    int vis[110000] = {0};
    TreeNode* dfs(TreeNode* root)
    {
        if(root == NULL)
        {
            return NULL;
        }

        TreeNode* left = dfs(root->left);
        TreeNode* right =dfs(root->right);

        if(left!=NULL)
        {
            adj[root->val].push_back(left->val);
            adj[left->val].push_back(root->val);
        }
        if(right!=NULL)
        {
            adj[root->val].push_back(right->val);
            adj[right->val].push_back(root->val);
        }
        return root;
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);

        queue<pair<int,int>> q;
        q.push({start,0});

        int lvl=0;
        int mx = 0;
        
        vis[start]=1;
        while(!q.empty())
        {
            int currNode = q.front().first;
            int currCount = q.front().second;
            q.pop();

            mx = max(mx, currCount);
            for(auto it:adj[currNode])
            {
                if(!vis[it])
                {
                    q.push({it,currCount+1});
                    vis[it]=1;
                }
            }
        }

        return mx;
    }
};