#include <string>
using namespace std;






char findTheDifference(string s, string t) {
    int count[26];
    memset(count , 0 , sizeof(count));
    for (char c : s) count[c-'a'] ++;
    for (char c : t) {
        count[c-'a'] --;
        if (count[c-'a'] < 0) return c;
    }
    return count[0];
}