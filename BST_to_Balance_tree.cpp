class Solution {
public:
    // Helper function to perform inorder traversal and store the node values in a vector
    void inorderTraversal(TreeNode* root, vector<int>& nodes) {
        if (root == nullptr) {
            return;
        }
        inorderTraversal(root->left, nodes);
        nodes.push_back(root->val);
        inorderTraversal(root->right, nodes);
    }
    
    // Helper function to build a balanced BST from the sorted array
    TreeNode* buildBalancedBST(vector<int>& nodes, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);
        root->left = buildBalancedBST(nodes, start, mid - 1);
        root->right = buildBalancedBST(nodes, mid + 1, end);
        return root;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorderTraversal(root, nodes);
        return buildBalancedBST(nodes, 0, nodes.size() - 1);
    }
};