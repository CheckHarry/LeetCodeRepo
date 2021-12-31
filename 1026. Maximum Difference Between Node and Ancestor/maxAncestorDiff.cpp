#include <vector>
#include <math.h>
using namespace std;
#define max_3(a,b,c) max(max(a,b) , c)
#define min_3(a,b,c) min(min(a,b) , c)

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


  vector<int> maxAncestorDiff_recursive(TreeNode* root){
        if (root -> left == nullptr and root -> right == nullptr){
            return vector<int> ({0 , root -> val , root -> val});
        }
        else if (root -> left == nullptr){
            vector<int> right_tree_info = maxAncestorDiff_recursive(root -> right);
            right_tree_info[0] = max_3( right_tree_info[0] , abs(right_tree_info[1] - root->val) , abs(right_tree_info[2] - root->val));
            if (root -> val < right_tree_info[2]) {right_tree_info[2] = root ->val;}
            else if(root -> val > right_tree_info[1]){ right_tree_info[1] = root -> val;}
            return right_tree_info;
        }
        else if (root -> right == nullptr){
            vector<int> left_tree_info = maxAncestorDiff_recursive(root -> left);
            left_tree_info[0] = max_3( left_tree_info[0] , abs(left_tree_info[1] - root->val) , abs(left_tree_info[2] - root->val));
            if (root -> val < left_tree_info[2]) {left_tree_info[2] = root ->val;}
            else if(root -> val > left_tree_info[1]){ left_tree_info[1] = root -> val;}
            return left_tree_info;
        }
        else{
            vector<int> left_tree_info = maxAncestorDiff_recursive(root -> left);
            vector<int> right_tree_info = maxAncestorDiff_recursive(root -> right);
            left_tree_info[0] = max_3( left_tree_info[0] , abs(left_tree_info[1] - root->val) , abs(left_tree_info[2] - root->val));
            right_tree_info[0] = max_3( right_tree_info[0] , abs(right_tree_info[1] - root->val) , abs(right_tree_info[2] - root->val));
            left_tree_info[0] = max(left_tree_info[0] , right_tree_info[0]);
            left_tree_info[1] = max_3(left_tree_info[1] , right_tree_info[1] , root -> val);
            left_tree_info[2] = min_3(left_tree_info[2] , right_tree_info[2] , root -> val);
            return left_tree_info;
        }
    }

int main(){

}