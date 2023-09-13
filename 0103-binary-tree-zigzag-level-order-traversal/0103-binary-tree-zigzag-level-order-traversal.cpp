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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL) {
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while (!q.empty()) {
            vector<int> level1;
            int s = q.size();
            
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                if (level == 0) {
                    level1.push_back(node->val);  // Push elements to the vector
                } else {
                    level1.insert(level1.begin(), node->val);  // Insert elements at the beginning
                }
                
                if (node->left != NULL) q.push(node->left);
                if (node->right != NULL) q.push(node->right);
            }
            
            ans.push_back(level1);
            level = 1 - level;  // Toggle level for zigzag
        }
        
        return ans;
    }
};
