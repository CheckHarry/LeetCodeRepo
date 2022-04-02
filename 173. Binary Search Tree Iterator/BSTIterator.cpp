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

class BSTIterator
{
    vector<pair<TreeNode * , int>> parents;
public:
    BSTIterator(TreeNode *root)
    {
        parents.push_back({root , 1});
    }

    int next()
    {   
        while (true){
            parents.back().second ++;
            if (parents.back().second == 2 ){
                if (parents.back().first -> left){
                    parents.push_back({parents.back().first -> left , 1});
                }
            }
            else if (parents.back().second == 3){
                break;
            }
            else if (parents.back().second == 4){
                if (parents.back().first -> right){
                    parents.push_back({parents.back().first -> right , 1});
                }
            }
            else{
                parents.pop_back();
            }
        }
        return parents.back().first -> val;
    }

    bool hasNext()
    {
        for (auto& p : parents){
            if (p.second <= 2)
                return true;
            else if(p.second == 3 && p.first->right)
                return true;
        }
        return false;
    }
};