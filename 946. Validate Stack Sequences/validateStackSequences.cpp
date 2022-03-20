#include <vector>
#include <stack>
using namespace std;




bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    int  push_pos = 0 , pop_pos = 0 ;
    stack<int> s;
    while (true){
        if (!s.empty() && pop_pos < popped.size() && s.top() == popped[pop_pos]) {
            s.pop();
            pop_pos ++;
        }
        else if (push_pos < pushed.size()){
            s.push(pushed[push_pos]);
            push_pos ++;
        }
        else break;
    }
    return s.empty();
}