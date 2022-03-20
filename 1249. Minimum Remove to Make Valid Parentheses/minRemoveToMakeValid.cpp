#include <string>
#include <stack>
#include <algorithm>
using namespace std;




string minRemoveToMakeValid(string s) {
    stack<int> p_stack;
    string to_return = "";
    for (int i = 0 ; i < s.size() ; i ++){
        if (s[i] == '(') p_stack.push(i);
        else if (s[i] == ')') {
            if (p_stack.empty() || s[p_stack.top()] != '(') p_stack.push(i);
            else p_stack.pop();
        }
    }
    for (int i = s.size() - 1 ; i >= 0 ; i --){
        if (!p_stack.empty() && i == p_stack.top()) p_stack.pop();
        else to_return += s[i];
    }
    reverse(to_return.begin() , to_return.end());
    return to_return;
}


int main(){
    
}

