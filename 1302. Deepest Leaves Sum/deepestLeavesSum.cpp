#include <utility> 
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void dfs(TreeNode *node, int layer, pair<int, int> &p)
{
    if (!node)
        return;
    dfs(node->left, layer + 1, p);
    if (p.first < layer)
        p = {layer, node->val};
    else if (p.first == layer)
        p.second += node->val;

    dfs(node->right, layer + 1, p);
}

int deepestLeavesSum(TreeNode *root)
{
    pair<int, int> p{0, 0};
    dfs(root, 0, p);
    int m = 0;
    return p.second;
}