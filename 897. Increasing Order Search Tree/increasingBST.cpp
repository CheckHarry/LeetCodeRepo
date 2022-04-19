#include <utility>
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

class Solution
{
public:
    TreeNode *cur = nullptr;
    void tranverse(TreeNode *node)
    {

        if (!node)
            return;
        tranverse(node->right);
        node->right = cur;
        cur = node;
        tranverse(node->left);
        node->left = nullptr;
    }

    TreeNode *increasingBST(TreeNode *root)
    {

        tranverse(root);
        return cur;
    }
};