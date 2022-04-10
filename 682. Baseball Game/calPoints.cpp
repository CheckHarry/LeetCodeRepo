#include <vector>
#include <string>
using namespace std;



int calPoints(vector<string> &ops)
{
    vector<int> records;
    int ans = 0;
    for (string &s : ops)
    {
        if (s == "C")
        {
            records.pop_back();
        }
        else if (s == "D")
        {
            records.push_back(records[records.size() - 1] * 2);
        }
        else if (s == "+")
        {
            records.push_back(records[records.size() - 1] + records[records.size() - 2]);
        }
        else
            records.push_back(stoi(s));
    }
    for (int i : records)
        ans += i;
    return ans;
}