#include <stack>
#include <string>
using namespace std;


int pow(int x , int y){
    if (y == 0) return 1;
    else return x * pow(x , y - 1);
}

int scoreOfParentheses(string s) {
    int ans = 0 , depth = 0;
    for (int i = 0 ; i < s.size() ; i ++){
        if (s[i] == '(') depth ++;
        else{
            depth --;
            if (s[i-1] == '(') ans += pow(2 , depth);
        }
    }
    return ans;
}