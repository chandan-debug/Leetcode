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

class BSIIterator{
    stack<TreeNode *> mystack;
    // reverse->true ->before
    //reverse->false->next
    bool reverse=true; // reverse here is before
    public:
    
    BSIIterator(TreeNode *root, bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    bool hasnext(){
        return !mystack.empty();
    }
    int next(){
        TreeNode* tempNode=mystack.top();
        mystack.pop();
        if(!reverse) pushAll(tempNode->right);
        else pushAll(tempNode->left);
        return tempNode->val;
    }
    private:
    void pushAll(TreeNode* node){
        for(;node!=NULL;){
            mystack.push(node);
                if(reverse==true){
                    node=node->right;
                }
            else{
                node=node->left;
            }
        }
    }
    
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root)
            return false;
        BSIIterator l(root,false);
        BSIIterator r(root,true);
        
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) 
                i=l.next();
            else j=r.next();
        }
        return false;
    }
};