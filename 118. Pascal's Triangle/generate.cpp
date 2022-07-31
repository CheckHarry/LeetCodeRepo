#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> to_return{vector<int> {1}};
        for (int i = 1 ; i < numRows  ; i ++)
        {
            vector<int> to_push{1};
            for (int j = 1 ; j < to_return.back().size() ; j ++)
            {
                to_push.push_back(to_return.back()[j] + to_return.back()[j - 1]);
            }
            to_push.push_back(1);
            to_return.push_back(to_push);
        }
        return to_return;
    }
};