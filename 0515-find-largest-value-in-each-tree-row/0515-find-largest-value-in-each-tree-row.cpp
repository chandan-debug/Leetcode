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
    vector<int> largestValues(TreeNode* root) 
    {
         vector<int> big;
        
        if (root == nullptr)
            return big;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty())
        {
            int n = q.size();
            int maxi = INT_MIN;
            
            for (int i = 0; i < n; i++)
            {
                auto frontroot = q.front();
                q.pop();
                maxi = max(maxi, frontroot->val);
                
                if (frontroot->left != nullptr)
                    q.push(frontroot->left);
                
                if (frontroot->right != nullptr)
                    q.push(frontroot->right);
            }
            
            big.push_back(maxi);
        }
        
        return big;
    }
};