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
        else return false;#include <unordered_map>
#include <unordered_set>
#include <stdlib.h>
#include <iostream>
using namespace std;





class RandomizedCollection {
public:
    RandomizedCollection() {

    }

    bool insert(int val) {
        nums_vec.push_back(val);
        if (multiset.find(val) == multiset.end()) { multiset.insert(pair<int, unordered_set<unsigned int>>(val, { (unsigned int)(nums_vec.size() - 1 )})); return true; }
        else { (*multiset.find(val)).second.insert(nums_vec.size() - 1); return false; }
        return true;
    }

    bool remove(int val) {
        if (multiset.find(val) != multiset.end()) {
            unordered_set<unsigned int>& vec = (*multiset.find(val)).second;
            unordered_set<unsigned int>::iterator it = vec.begin();
            int temp = *it;
            vec.erase(it);
            if (vec.empty()) multiset.erase(val);
            if (temp != nums_vec.size() - 1) {
                nums_vec[temp] = nums_vec[nums_vec.size() - 1];
                (*multiset.find(nums_vec[nums_vec.size() - 1])).second.erase(nums_vec.size() - 1);
                (*multiset.find(nums_vec[nums_vec.size() - 1])).second.insert(temp);
            }
            vector<int>::iterator it_vec = nums_vec.end();
            it_vec--;
            nums_vec.erase(it_vec);
          
            return true;
        }
        else return false;
    }

    int getRandom() {
        return nums_vec[rand() % nums_vec.size()];
    }
private:
    unordered_map<int, unordered_set<unsigned int>> multiset;
    vector<int> nums_vec;
};



int main() {
    RandomizedCollection RC;
    RC.insert(1);
    RC.insert(1);
    RC.insert(2);
    RC.remove(1);
   
    int count1 = 0, count2 = 0;
    for (int i = 0; i < 100000; i++) {
        if (RC.getRandom() == 1) count1++;
        else count2++;
    }
    cout << count1 << '\n';
    cout << count2 << '\n';
}
    }

    int getRandom() {
        return nums_vec[rand() % nums_vec.size()];
    }
private:
    unordered_map<int, vector<unsigned int>> multiset;
    vector<int> nums_vec;
};