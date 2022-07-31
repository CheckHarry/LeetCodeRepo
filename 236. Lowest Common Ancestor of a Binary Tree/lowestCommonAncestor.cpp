

struct TreeNode {
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
    TreeNode *ans = nullptr;
    int tranversal(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root || ans != nullptr)
            return 0;

        int count = 0;
        count += tranversal(root->left, p, q);
        count += tranversal(root->right, p, q);
        if (root == p || root == q)
        {
            count++;
        }
        if (count == 2 && ans == nullptr)
            ans = root;

        return count;
    }

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        tranversal(root, p, q);
        return ans;
    }
};