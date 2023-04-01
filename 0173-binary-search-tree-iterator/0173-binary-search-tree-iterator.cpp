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
class BSTIterator {
 private:   stack<TreeNode *> mystack;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);     
    }
    /*retrun whether we have a next smallest number*/
    
     bool hasNext() {  
        return !mystack.empty();     
    }
     
    /* return the next smallest number*/
    
    int next() {
        TreeNode* tempNode=mystack.top(); 
        mystack.pop();
        pushAll(tempNode->right);
        return tempNode->val;   
    }
      
   
    private:
    void pushAll(TreeNode *node){
        for(; node!=NULL ; mystack.push(node), node=node->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */