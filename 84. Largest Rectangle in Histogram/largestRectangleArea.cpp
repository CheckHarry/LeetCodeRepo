#include <vector>
#include <stack>
#include <iostream>
using namespace std;




int largestRectangleArea(vector<int>& heights) {
    int ans = 0;
    stack<int> bound;
    vector<int> left(heights.size()) , right(heights.size());
    bound.push(-1);
    for (int i = 0 ; i < heights.size() ; i ++){
        while(bound.top() != -1 && heights[bound.top()] >= heights[i]) bound.pop();
        left[i] = bound.top();
        bound.push(i);
    }
    bound = stack<int>();
    bound.push(heights.size());
    for (int i = heights.size() - 1 ; i >= 0 ; i --){
        while(bound.top() != heights.size() && heights[bound.top()] >= heights[i]) bound.pop();
        right[i] = bound.top();
        bound.push(i);
    }
    for (int x : left) cout << x << ','; 
    cout << '\n';
    for (int x : right) cout << x << ',';
    for (int i = 0 ;i < heights.size() ; i ++) ans = max((right[i] - left[i] - 1) * heights[i] , ans);
    return ans;
}


int main(){
    vector<int> x{2,1,5,6,2,3,2,5,6,3,21,2,5,7,4,10,4,7,31,10,6,1,7,8,5};
    cout << largestRectangleArea(x);
}