#include <algorithm>
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

void recoverTree(TreeNode *root)
{
    TreeNode *cur = root, *pred = nullptr, *left = nullptr, *right = nullptr;
    while (cur)
    {
        if (cur->left)
        {
            TreeNode *rm = cur->left;
            while (rm->right && rm->right != cur)
                rm = rm->right;

            if (rm->right == cur)
            {
                if (pred && pred->val >= cur->val)
                {
                    if (!left)
                        left = pred;
                    right = cur;
                }
                pred = cur;
                rm->right = nullptr;
                cur = cur->right;
            }
            else
            {
                rm->right = cur;
                cur = cur->left;
            }
        }
        else
        {
            if (pred && pred->val >= cur->val)
            {
                if (!left)
                    left = pred;
                right = cur;
            }
            pred = cur;
            cur = cur->right;
        }
    }
    swap(left->val, right->val);
}