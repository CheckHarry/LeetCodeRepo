#include <string>
#include <vector>
#include <iostream>
using namespace std;




bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;
    vector<int> count(26 , 0);
    int count0 = 0;
    for (char x : s1) count[x-'a'] ++;
    for (int i = 0 ; i < s1.size() ; i ++) count[s2[i] - 'a'] --;
    for (int i : count) if(i == 0) count0 ++;
    for (int i = 0 ; i < s2.size() - s1.size() ; i ++){
        if (count0 == 26) return true;
        count[s2[i] - 'a'] ++;
        if (count[s2[i] - 'a'] == 1) count0 --;
        else if (count[s2[i] - 'a'] == 0) count0 ++;
        count[s2[i + s1.size()] - 'a'] --;
        if (count[s2[i + s1.size()] - 'a'] == -1) count0 --;
        else if (count[s2[i + s1.size()] - 'a'] == 0) count0 ++;
    }
    if (count0 == 26) return true;
    return false;
}

int main(){
    string s1 = "adc", s2 = "dcda";
    cout << checkInclusion(s1 , s2);
}