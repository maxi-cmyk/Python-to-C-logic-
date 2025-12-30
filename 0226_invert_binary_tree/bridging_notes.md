struct TreeNode* invertTree(struct TreeNode* root) {
    // 1. Base Case
    if (root == NULL) {
        return NULL;
    }

    // 2. The Swap (Standard C swap logic)
    struct TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 3. The Recursive Calls
    invertTree(root->left);
    invertTree(root->right);

    return root;
}