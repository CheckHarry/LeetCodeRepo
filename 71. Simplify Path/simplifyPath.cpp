#include <vector>
#include <string>
#include <stack>
#include <iostream>
using namespace std;




string simplifyPath(string path) {
    stack<string> simplify;
    string temp = "" , to_return = "";
    bool start = true;
    for (char x : path){
        if (x == '/') {
            if (!temp.size()) continue;
            if (temp == "..") {if (!simplify.empty()) simplify.pop();}
            else if(temp != ".") simplify.push(temp);
            temp = "";
        }
        else temp += x;
    }
    if (temp.size()) {
        if (temp == "..") {if (!simplify.empty()) simplify.pop();}
        else if(temp != ".") simplify.push(temp);
    }
    
    while (!simplify.empty()) {
        to_return =  "/" + (simplify.top() + to_return);
        simplify.pop();
    }

    return to_return.empty() ? "/" : to_return;
}


int main(){
    cout << simplifyPath("//home/../etc/./abc/../doc");
}

