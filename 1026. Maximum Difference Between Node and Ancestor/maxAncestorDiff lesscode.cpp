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


int ans = 0;
    
int maxAncestorDiff(TreeNode* root) {
int Max = -1 , Min = 50001 ;    
maxAncestorDiff_recursive(Max , Min, root);
    return ans;
}
void maxAncestorDiff_recursive(int &Max , int &Min , TreeNode* root){
    if (!root) return;
    int temp_left_max = -1 , temp_right_max = -1 , temp_left_min = 50001, temp_right_min = 50001;
    maxAncestorDiff_recursive(temp_left_max , temp_left_min  , root -> left);
    maxAncestorDiff_recursive(temp_right_max , temp_right_min  , root -> right);
    Max = max_3(temp_left_max , temp_right_max , root -> val);
    Min = min_3(temp_left_min , temp_right_min , root -> val);
    ans = max_3(ans , abs(Max - root ->val) , abs(Min - root -> val));
}