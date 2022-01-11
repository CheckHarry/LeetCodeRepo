


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


void NodeTraversal(TreeNode* root , int value , int &ans){
    int temp = 2 * value + root -> val;
    if (root -> left == nullptr && root -> right == nullptr) ans += temp;
    if (root -> left != nullptr) NodeTraversal(root -> left , temp , ans);
    if (root -> right != nullptr) NodeTraversal(root -> right , temp , ans);
}

int sumRootToLeaf(TreeNode* root) {
    int ans = 0;
    NodeTraversal(root , 0 , ans);
    return ans;
}
    
