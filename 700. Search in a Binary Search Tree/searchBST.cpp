

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *searchBST(TreeNode *root, int val)
{
    TreeNode *cur = root;
    while (cur != nullptr)
    {
        if (cur->val == val)
            return cur;
        else if (cur->left && cur->val > val)
            cur = cur->left;
        else if (cur->right && cur->val < val)
            cur = cur->right;
        else
            return nullptr;
    }
    return nullptr;
}