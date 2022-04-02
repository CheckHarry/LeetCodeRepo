#include <vector>
#include <algorithm>
using namespace std;

int numRescueBoats(vector<int> &people, int limit) {
    sort(people.begin(), people.end());
    int left = 0, right = people.size() - 1, ans = 0;
    while (right >= left)
    {
        if (people[left] + people[right] > limit)
        {
            right--;
        }
        else
        {
            left++;
            right--;
        }
        ans++;
    }
    return ans;
}