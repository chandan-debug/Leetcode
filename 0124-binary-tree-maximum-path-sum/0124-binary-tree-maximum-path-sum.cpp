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
    int solve(TreeNode*root,int& pathsum){
        if(root==NULL){
            return 0;
        }
       int lh = max(0, solve(root->left, pathsum)); // Calculate the left subtree path sum
        int rh = max(0, solve(root->right, pathsum)); // Calculate the right subtree path sum

     pathsum = max(pathsum, lh + rh + root->val);       
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {
        int pathsum=INT_MIN;
        solve(root,pathsum);
        return pathsum;
        
    }
};