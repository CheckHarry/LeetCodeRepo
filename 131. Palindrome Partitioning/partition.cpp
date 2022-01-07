#include <vector>
#include <string>
#include <iostream>
using namespace std;



void dfs(vector<vector<int>>& table , vector<vector<string>>& to_return , vector<string> & vec_string , int pos , string& s ){
    for (int i : table[pos]){
        vec_string.push_back(s.substr(pos , i));
        if(pos + i == s.size()) to_return.push_back(vec_string);
        else dfs(table , to_return , vec_string , pos + i, s);
        vec_string.pop_back();
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<int>> table(s.size() , vector<int> {});
    vector<vector<string>> to_return;
    vector<string> vec_string{};
    for (int i = 0 ; i < 2 * s.size() ; i ++){
        int left = i / 2 ,right = i / 2 + i % 2;    
        for (int j = 0 ; 0 <= left - j && right + j <= s.size() - 1 && s[left - j] == s[right + j] ; j ++ ){
            table[left - j].push_back(2*j + 1 + i%2);
        }
    }
    dfs(table , to_return , vec_string , 0 , s);
    return to_return;
}



int main(){
    
    for (vector<string> &a : partition("aabaa")){
        for (string s : a ) cout << s << ',';
        cout << '\n';
    }
}