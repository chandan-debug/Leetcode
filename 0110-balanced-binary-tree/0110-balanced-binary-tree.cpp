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
    bool isBalanced(TreeNode* root) {
        if(root==NULL )
            return true;
        int height=1;
        bst(root,height);
        
        if(height) return true;
        else return false;
        
        
    }
    int bst(TreeNode* root, int& height){
        if(root==NULL )
            return 0;
        int left=bst(root->left,height)+1;
        int right=bst(root->right,height)+1;
        if(abs(right-left)>1) height=0;
        
        return max(left,right);
        
    }
};