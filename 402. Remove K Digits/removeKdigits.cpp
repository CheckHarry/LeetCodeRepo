#include <string>
#include <stack>
#include <iostream>
using namespace std;








string removeKdigits(string num, int k) {
    int count  = 0 , i = 0;
    string ans = "" , temp = "";
    stack<int> s;
    for (; i < num.size() ; i ++){
        if (s.empty()) s.push(num[i]);
        else{
            while(true){
                if (!s.empty() && num[i] < s.top()) s.pop();
                else break;
                count ++;
                if (count == k) break;
            }
            s.push(num[i]);
        }
        if (count == k) break;
    }
    
    if (i < num.size()) temp = num.substr(i + 1);
    while(!s.empty()){
        if(count ++ >= k) temp = (char) s.top() + temp;
        s.pop();
    }
    i = 0;
    for (;i < temp.size();i ++){
        if (temp[i] != '0') break;
    }
    if (i < temp.size()) ans = temp.substr(i);
    return ans == "" ? "0" : ans;
}



int main(){
    string s = "10200";
  
    cout << removeKdigits(s , 2);
}

