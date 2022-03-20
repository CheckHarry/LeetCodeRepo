#include <stack>
#include <string>
using namespace std;








int scoreOfParentheses(string a) {
    int ans = 0 ;
    stack<int> s;
    for (char c : a){
        if (c == '(') s.push(0);
        else {
            int temp = 0;
            while (s.top() != 0){
                temp += s.top();
                s.pop();
            }
            if (temp == 0) s.top() += 1;
            else s.top() = temp * 2;
        }
    }
    while (!s.empty()){
        ans += s.top();
        s.pop();
    }
    return ans;
}