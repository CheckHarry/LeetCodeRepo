#include <vector>
#include <stack>
#include <iostream>
using namespace std;




int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    stack<int> bound;
    vector<int> left(heights.size() , -1) , right(heights.size() , heights.size());
    bound.push(-1);
    for (int i = 0 ; i < heights.size() ; i ++){
        while(bound.top() != -1 && heights[bound.top()] >= heights[i]) {
            right[bound.top()] = i;
            bound.pop();
        }
        left[i] = bound.top();
        bound.push(i);
    }
    for (int i = 0 ;i < heights.size() ; i ++) ans = max((right[i] - left[i] - 1) * heights[i] , ans);
    return ans;
}


int main(){
    vector<int> x{2,1,5,6,2,3};
    cout << largestRectangleArea(x);
}