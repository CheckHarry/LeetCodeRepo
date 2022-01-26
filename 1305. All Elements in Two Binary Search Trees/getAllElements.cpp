#include <vector>
#include <algorithm>
using namespace std;



struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void Traversal(vector<int> &vec , TreeNode* root){
    if (root == nullptr) return;
    Traversal(vec , root -> left);
    vec.push_back(root -> val);
    Traversal(vec , root -> right);
}
    
    
vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> to_return;
    Traversal(to_return , root1);
    Traversal(to_return , root2);
    sort(to_return.begin() , to_return.end());
    return to_return;
}