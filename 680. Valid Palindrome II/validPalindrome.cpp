#include <string>
using namespace std;

bool check(string &s, int left, int right)
{
    while (left < right)
    {
        if (s[left] != s[right])
            break;
        left++;
        right--;
    }
    if (left >= right)
        return true;
    else
        return false;
}

bool validPalindrome(string s)
{
    int left = 0, right = s.size() - 1;
    bool l = false, r = false;
    while (left < right)
    {
        if (s[left] != s[right])
            break;
        left++;
        right--;
    }
    if (left >= right)
        return true;

    if (s[left] == s[right - 1])
    {
        if (check(s, left, right - 1))
            return true;
    }
    if (s[left + 1] == s[right])
    {
        if (check(s, left + 1, right))
            return true;
    }

    return false;
}