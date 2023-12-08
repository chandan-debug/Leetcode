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
    void solve(TreeNode*node,string& s){
        if(node==NULL) {
            //s+='()';
            return;
        }

        s+=to_string(node->val);
        if(node->left!=NULL||node->right!=NULL){
            s+='(';
            
        }
         solve(node->left,s);
         if(node->left==NULL&&node->right!=NULL) s+='()';
        if(node->right!=NULL)s+='(';
         solve(node->right,s);
         s+=')';
    
    }
    string tree2str(TreeNode* root) {
        string s="";
        solve(root,s);
        s.pop_back();
        return s;
    }
};