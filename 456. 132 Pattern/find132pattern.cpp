#include <vector>
#include <stack>
#include <iostream>
using namespace std;



bool find132pattern(vector<int> &nums)
{
    stack<int> r;
    vector<int> v_min(nums.size() , 0);
    
    v_min[0] = INT_MAX;
       
    for (int i = 1; i < nums.size(); i++)
    { 
        v_min[i] = min(v_min[i - 1] , nums[i - 1]);
    }
       
    for (int i = nums.size() - 1 ; i >= 0 ; i --)
    {
        int a = INT_MIN;
        while (!r.empty() && nums[r.top()] < nums[i])
        {
            a = nums[r.top()];
            r.pop();
        }
            
        if (a > v_min[i])
            return true;

        r.push(i);
    }
       
       
    return false;
}

int main()
{   
    vector<int> x({0,2,-1,4});
    cout << find132pattern(
        x
    )   ;
}