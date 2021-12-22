#include <unordered_map>
#include <stdlib.h>
using namespace std;





class RandomizedCollection {
public:
    RandomizedCollection() {

    }

    bool insert(int val) {
        nums_vec.push_back(val);
        if (multiset.find(val) == multiset.end())  multiset.insert(pair<int, vector<unsigned int>>(val, { nums_vec.size() - 1 }));
        else (*multiset.find(val)).second.push_back(nums_vec.size() - 1);
    }

    bool remove(int val) {
        if (multiset.find(val) == multiset.end()) {
            vector<unsigned int>& vec = (*multiset.find(val)).second;
            vector<unsigned int>::iterator it = vec.end();
            it--;
            int temp = *it;
        }
        else return false;
    }

    int getRandom() {
        return nums_vec[rand() % nums_vec.size()];
    }
private:
    unordered_map<int, vector<unsigned int>> multiset;
    vector<int> nums_vec;
};