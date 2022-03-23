#include <string>
using namespace std;

string countAndSay(int n)
{
    string ans = "1";
    for (int i = 2; i <= n; i++)
    {
        string temp = "";
        int count = 0;
        char cur = '0';
        for (char c : ans)
        {
            if (c == cur)
                count++;
            else
            {
                if (count != 0)
                {
                    temp += char(count + '0');
                    temp += cur;
                }
                cur = c;
                count = 1;
            }
        }
        temp += char(count + '0');
        temp += cur;
        ans = move(temp);
    }
    return ans;
}