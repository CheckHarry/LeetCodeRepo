#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;



class LRUCache {
public:
    int capacity_cache = 0 , size = 0;
    list<pair<int,int>> recently_used;
    unordered_map<int, list<pair<int,int>>::iterator> mapping;
    LRUCache(int capacity) {
        capacity_cache = capacity;
    }

    int get(int key) {
        if (mapping.find(key) != mapping.end()) {
            list<pair<int,int>>::iterator it = mapping.find(key)->second;
            pair<int,int> temp = *it;
            recently_used.erase(it);
            recently_used.push_back(temp);
            mapping[key] = --recently_used.end();
            return temp.second;
        }
        else return -1;
    }

    void put(int key, int value) {

        if (mapping.find(key) != mapping.end()) { 
            recently_used.erase(mapping.find(key)->second); 
            mapping.erase(key);
        }
        else size++;
           
        recently_used.push_back(pair<int,int>(key , value));
        list<pair<int,int>>::iterator it = recently_used.end();
        mapping.insert(pair<int, list<pair<int, int>>::iterator>(key, --it ));
        if (size > capacity_cache) {
            list<pair<int, int>>::iterator it = recently_used.begin();
            mapping.erase(it->first);
            recently_used.erase(it);
            size--;
        }
    }
};


int main() {
    LRUCache cache(2);
    cache.put(1, 0);
    cache.put(2, 2);
    cache.put(2, 5);
    cout << cache.get(1) << endl;
    
    cout << cache.get(2) << endl;
    cache.put(4, 4);
    cout << cache.get(1) << endl;
    cout << cache.get(3) << endl;
    cout << cache.get(4) << endl;
}