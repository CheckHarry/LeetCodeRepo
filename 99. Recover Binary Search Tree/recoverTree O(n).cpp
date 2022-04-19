#include <vector>
using namespace std;



struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void tranverse(TreeNode *root, TreeNode *&pred, vector<TreeNode *> &to_swap)
{
    if (!root)
        return;
    tranverse(root->left, pred, to_swap);
    if (pred && pred->val >= root->val)
    {
        to_swap.push_back(pred);
        to_swap.push_back(root);
    }
    pred = root;
    tranverse(root->right, pred, to_swap);
}

void recoverTree(TreeNode *root)
{
    vector<TreeNode *> to_swap;
    TreeNode *pred = nullptr;
    tranverse(root, pred, to_swap);
    swap(to_swap[0]->val, to_swap.back()->val);
}