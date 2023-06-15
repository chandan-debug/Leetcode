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

class NodeVal{
    public:
    bool isBst;
    int minNode,maxNode,maxSum;
    NodeVal(){
        isBst = true;
        minNode = INT_MAX;
        maxNode = INT_MIN;
        maxSum= 0;
    }
};
int ans;
class Solution {
public:
    NodeVal FindSum(TreeNode* root){
    if(root == NULL) return NodeVal();
    NodeVal curr;
    //Now take 2 pointer for left and right 
    //-- we are going to perform POSTORDER TRAVERSAL
    NodeVal left = FindSum(root->left);
    NodeVal right = FindSum(root->right);

    /*
    Checking main condition of BST:
    -----------Left < ROOT < RIGHT-----------
    
*/
    if((left.isBst==true && right.isBst == true) && (left.maxNode<root->val && root->val<right.minNode)){
        // make curr bst as bst 
        curr.isBst = true;
        //Below is our answer
        curr.maxSum = left.maxSum + right.maxSum+root->val;
        // now store minimal node or the left node as it's a BST  
        curr.minNode= min(left.minNode,root->val);
        // now store maximum node or the right node for bst
        curr.maxNode = max(right.maxNode,root->val);
    }
    /*if the given Binary Tree is Not a BST*/
    else{
        curr.isBst = false; // else mark it false saying "No, its NOT BST"
        curr.maxSum = max(left.maxSum,right.maxSum);// keep updating maxSum
    }
    ans = max(ans,curr.maxSum);// store current answer 
    return curr;
}
    int maxSumBST(TreeNode* root) {
        ans =0;
        NodeVal obj = FindSum(root);
        return ans;
    }
};