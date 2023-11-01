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
    void helper(TreeNode* root,unordered_map<int,int>& ans){
        if(root==NULL){
            return;
        }
        ans[root->val]++;
        helper(root->left,ans);
        helper(root->right,ans);
    }
    vector<int> findMode(TreeNode* root) {
        unordered_map<int,int> ans;
        helper(root,ans);
        int max=0;
        for(auto it:ans){
            if(it.second>max){
                max=it.second;
            }
        }
        vector<int> n;
        for(auto it:ans){
            if(it.second==max){
                n.push_back(it.first);
            }
        }
        return n;
    }
};