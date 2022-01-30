#include <string>
#include <vector>
#include <iostream>
using namespace std;



struct TrieNode{
    bool is_end = false;
    vector<TrieNode*> vec{26 , nullptr};
};


class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode;
    }
    
    void insert(string word) {
        TrieNode* cur = root;
        int count = 0;
        for (char x : word){
            count ++;
            if (cur -> vec[ x - 'a'] != nullptr) cur = cur -> vec[ x - 'a'];
            else{
                TrieNode* newptr = new TrieNode;
                cur -> vec[x - 'a'] = newptr;
                cur = newptr;
            }
            if (count == word.size()) cur -> is_end = true;
        }
    }
    
    bool search(string word) {
        TrieNode* cur = root;
        for (char x : word){
            if (cur -> vec[ x - 'a'] != nullptr) cur = cur -> vec[ x - 'a'];
            else return false;
        }
        return cur -> is_end;
    }
    
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char x : prefix){
            if (cur -> vec[ x - 'a'] != nullptr) cur = cur -> vec[ x - 'a'];
            else return false;
        }
        return true;
    }
};


int main(){
    Trie x = Trie();
    x.insert("abc");
    cout << x.startsWith("abc") << '\n';
    cout << x.search("abc") << '\n';
    cout << x.startsWith("ab") << '\n';
    cout << x.search("ab") << '\n';
    x.insert("ab");
    cout << x.search("ab") << '\n';
}