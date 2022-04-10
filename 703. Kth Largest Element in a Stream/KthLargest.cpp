#include <queue>
using namespace std;


class KthLargest
{
public:
    int K;
    priority_queue<int , vector<int> , greater<int>> Q;
    KthLargest(int k, vector<int> &nums)
    {   
        K = k;
        for (int x : nums)
            Q.push(x);
    }

    int add(int val)
    {
        Q.push(val);
        while(Q.size() > K)
            Q.pop();
        return Q.top();
    }
};