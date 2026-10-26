class Solution {
public:
    vector<int> v;
    int idx = 0;

    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    void fill(TreeNode* root) {
        if (!root) return;
        fill(root->left);
        root->val = v[idx++];
        fill(root->right);
    }

    void recoverTree(TreeNode* root) {
        inorder(root);
        sort(v.begin(), v.end());
        fill(root);
    }
};