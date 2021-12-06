#include <array>
#include <string>
#include <iostream>
using namespace std;


void move(int& x, int m, int& i) {
    if (x == m - 1 or x == 0) {
        i *= -1;
    }
    x += i;
}


string convert(string s, int numRows) {
    if (numRows == 1) return s;
    array<string, 1000> array_string({ "" });
    string ans = "";
    int initial = -1 , pos = 0;
    for (char x : s) {
        array_string[pos] += x;
        move(pos, numRows, initial);
    }
    for (int i = 0; i < numRows; i++) {
        ans += array_string[i];
    }
    return ans;
}

int main() {
    cout << convert("AB", 1);
}