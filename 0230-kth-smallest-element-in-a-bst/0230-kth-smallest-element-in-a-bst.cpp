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
    int count=0;
    int ans=0;
    
    void recursion(TreeNode* root, int k){
        if(root->left!=NULL){
            recursion(root->left,k);
        }
        count++;
        if(count==k){
            ans=root->val;
            return;
        }
        if(root->right!=NULL){
        recursion(root->right,k);
    }
    }
   public: 
    int kthSmallest(TreeNode* root, int &k){
    
        recursion(root,k);
        return ans;
    }
        
    
    
   
};