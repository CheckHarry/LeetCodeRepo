#include <vector>
using namespace std;




struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};





int widthOfBinaryTree(TreeNode* root) {
    vector<TreeNode*> Node_vec;
    int ans = 0;
    Node_vec.push_back(root);
    while(!Node_vec.empty()){
        ans = max(ans , (int) Node_vec.size());
        vector<TreeNode*> New_vec;
        for (TreeNode *& node : Node_vec){  
            
        }
    }

}






