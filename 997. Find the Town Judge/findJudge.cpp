#include <vector>
using namespace std;

int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> people_trust(n + 1 , 0);
        vector<int> people_trusted(n + 1, 0);
        for (vector<int> pair : trust){
            people_trust[pair[0]] += 1;
            people_trusted[pair[1]] += 1;
        }
        for (int i = 1 ; i < n + 1 ; i++) if (people_trusted[i] == n - 1 && people_trust[i] == 0) return i;
            
        return -1;
    }