#include <vector>
#include <string>
#include <iostream>
#include <unordered_set>
using namespace std;




vector<string> generateParenthesis(int n) {
    vector<vector<string>> L{{"()"}};
    for (int i = 1 ; i < n ; i ++){
        L.push_back({});
        unordered_set<string> S;
        for (string str : L[i - 1]) L[i].push_back("(" + str + ")");
        for (int j = 1 ; j < i + 1  ; j ++){
            for (string str_l : L[j - 1]){
                for (string str_r : L[i - j]){
                    if(S.find(str_l + str_r) == S.end()){ 
                        L[i].push_back(str_l + str_r);
                        S.insert(str_l + str_r);
                    }
                }
            }
        }
    }
    return L[n - 1];
}


int main(){
    for  (string x : generateParenthesis(4)){
        cout << x << '\n';
    }
}