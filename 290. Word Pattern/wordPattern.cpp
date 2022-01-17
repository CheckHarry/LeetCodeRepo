#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
using namespace std;





bool wordPattern(string pattern, string s) {
    int count = 0;
    char cur = 'a';
    string token = "" , pattern_string = "";
    unordered_map<string , char> s2c;
    unordered_map<char , char> c2c;
    unordered_map<char , char> c2c2;
    s += ' ';
    for (char c : s){
        if (c == ' '){
            cout << token << '\n';
            if (s2c.find(token) != s2c.end()) pattern_string += s2c[token];
            else {
                s2c.insert(pair {token , cur});
                pattern_string += cur;
                cur ++;
            }
            token = "";
        }
        else token += c;
    }
    if (pattern.size() != pattern_string.size()) return false;
    for (int i = 0 ; i < pattern.size() ; i ++){
        if (c2c.find(pattern[i])!= c2c.end()){
            if (c2c[pattern[i]] != pattern_string[i]) return false;
        }
        else{
            if (c2c2.find(pattern_string[i]) != c2c2.end()) return false;
            c2c.insert(pair {pattern[i] , pattern_string[i]});
            c2c2.insert(pair {pattern_string[i] , pattern[i]});
        }
    }
    return true;
}

int main(){
    cout << wordPattern("abc" , "dog cat cat");
}