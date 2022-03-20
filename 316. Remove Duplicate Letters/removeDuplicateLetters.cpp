#include <string>
#include <vector>
#include <iostream>
using namespace std;










string removeDuplicateLetters(string s) {
    vector<int> count(26,0) , seen(26,0);
    string ans = "";
    for (char c : s) count[c - 'a'] ++;
    for (char c : s){
        if (!seen[c - 'a']){
            while (!ans.empty() && ans.back() > c){
                if (count[ans.back() - 'a'] > 0){
                    seen[ans.back() - 'a'] = 0;
                    ans.pop_back();
                }
                else break;
            }
            ans.push_back(c);
            seen[c - 'a'] = 1;
        }
        count[c - 'a'] --;
    }
    return ans;
}

int main(){
    string s = removeDuplicateLetters("cbacdcbc");
    cout << s;
}


