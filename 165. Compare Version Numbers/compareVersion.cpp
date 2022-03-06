#include <string>
#include <vector>
#include <iostream>
using namespace std;



vector<int> get_ver_vec(string &s , int size){
    string temp = "";
    vector<int> to_return;
    for (char x : s){
        if ( x == '.'){
            to_return.push_back(atoi(temp.data()));
            temp = "";
        }
        else temp = temp + x;
    }
    to_return.push_back(atoi(temp.data()));
    int to_return_size = to_return.size();
    if (size > to_return_size) {
        for (int i = 0 ; i < (size - to_return_size) ; i ++) {to_return.push_back(0);}
    }
    return to_return;
}

int compareVersion(string version1, string version2) {
    int a = 1 , b = 1 , len;
    for (char c : version1) if ( c == '.') a ++;
    for (char c : version2) if ( c == '.') b ++;
    len = max(a , b);
    vector<int> ver_vec1 = get_ver_vec(version1 , len) , ver_vec2 = get_ver_vec(version2 , len);
    for (int i = 0 ; i < len ; i ++) {
        if (ver_vec1[i] > ver_vec2[i]) return 1;
        else if (ver_vec1[i] != ver_vec2[i]) return -1;
    }
    return 0;
}

int main(){

    //for (int a : x) cout << a << '\n';
   compareVersion("1.0.01" , "1");
}