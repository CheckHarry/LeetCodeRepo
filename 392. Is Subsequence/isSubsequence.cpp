#include <string>
using namespace std;









bool isSubsequence(string s, string t) {
    if (s.size() == 0) return true;
    int pos = 0;
    for (char &c : t ) {
        if (c == s[pos]) pos ++;
        if (pos == s.size()) return true;
    }   
    return false;    
}