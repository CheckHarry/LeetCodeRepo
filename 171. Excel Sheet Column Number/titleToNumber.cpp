#include <string>
using namespace std;







int titleToNumber(string columnTitle) {
    int ans = 0;
    for (char x : columnTitle) ans = ans * 26 + (x - 'A' + 1);
    return ans;
}