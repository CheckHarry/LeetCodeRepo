#include <string>
#include <vector>
#include <iostream>
using namespace std;




vector<int> findAnagrams(string s, string p) {
    if (p.size() > s.size()) return {};
    vector<int> count(26 , 0) , count_s(26 , 0) , to_return;
    int match = 0;
    for (char c : p) count[c - 'a'] += 1;
    for (int i = 0 ; i < p.size() ; i ++) count_s[s[i] - 'a'] += 1;
    for (int i = 0 ; i < 26 ; i ++) if (count[i] == count_s[i]) match ++;                          
    for (int i = 0 ; i < s.size() - p.size() ; i ++){
        if(match == 26) to_return.push_back(i);
        if (s[i] - 'a' == s[i + p.size()] - 'a') continue;
        count_s[s[i] - 'a'] --;
        count_s[s[i + p.size()] - 'a'] ++;
        if(count_s[s[i] - 'a']     == count[s[i] - 'a']) match ++;
        else if((count_s[s[i] - 'a'] + 1 )== count[s[i] - 'a']) match --;
        if(count_s[s[i + p.size()] - 'a']     == count[s[i + p.size()] - 'a']) match ++;
        else if((count_s[s[i + p.size()] - 'a'] - 1) == count[s[i + p.size()] - 'a']) match --;
    }
    if(match == 26) to_return.push_back(s.size() - p.size());
    return to_return;
}


int main(){
    string s{"cbaaebabacd"} , p{"aabc"};
    auto ans = findAnagrams(s , p);
    for (int i : ans) cout << i << ',';

}