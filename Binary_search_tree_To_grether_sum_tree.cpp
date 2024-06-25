class Solution {
public:
    int sum = 0; // Global variable to keep track of the sum of all greater nodes
    
    TreeNode* bstToGst(TreeNode* root) {
        if (root != nullptr) {
            bstToGst(root->right); // Traverse right subtree
            
            // Update the current node with the sum of all greater nodes
            sum += root->val;
            root->val = sum;
            
            bstToGst(root->left); // Traverse left subtree
        }
        return root;
    }
};