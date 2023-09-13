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
    int widthOfBinaryTree(TreeNode* root) {
        // Check if the tree is empty
        if (!root) return 0;

        // Create a queue to perform level-order traversal
        queue<pair<TreeNode*, unsigned long long>> q;  // Use unsigned long long for the index
        q.push({root, 0});  // Push the root node with index 0
        int maxWidth = 0;   // Initialize maximum width

        while (!q.empty()) {
            int n = q.size();  // Number of nodes at the current level
            unsigned long long start = q.front().second;  // Start index of the current level
            unsigned long long end = q.back().second;    // End index of the current level

            // Calculate the width of the current level
            int width = static_cast<int>(end - start + 1);  // Cast to int

            // Update maxWidth if the current level is wider
            maxWidth = max(maxWidth, width);

            // Process nodes at the current level
            for (int i = 0; i < n; i++) {
                pair<TreeNode*, unsigned long long> p = q.front();
                TreeNode* node = p.first;
                unsigned long long idx = p.second;
                q.pop();

                // If there's a left child, calculate its index and enqueue it
                if (node->left) q.push({node->left, 2 * idx + 1});

                // If there's a right child, calculate its index and enqueue it
                if (node->right) q.push({node->right, 2 * idx + 2});
            }
        }

        return maxWidth;  // Return the maximum width of the binary tree
    }
};
