#include <vector>
#include <queue>
using namespace std;





int lastStoneWeight(vector<int> &stones)
{
    priority_queue<int> Q;
    for (int i : stones)
        Q.push(i);
    while (Q.size() > 1)
    {
        int x = Q.top();
        Q.pop();
        int y = Q.top();
        Q.pop();
        Q.push(x - y);
    }
    return Q.top();
}