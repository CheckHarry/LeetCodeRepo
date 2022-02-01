#include <string>
#include <vector>
#include <iostream>
using namespace std;



struct TrieNode{
    bool is_end = false;
    vector<TrieNode*> vec{26 , nullptr};
};


class WordDictionary {
private:
    TrieNode* root;
public:
    WordDictionary() {
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
        vector<TrieNode*> cur_nodes;
        cur_nodes.push_back(root);
        for (char x : word){
            vector<TrieNode*> next_nodes;
            for (TrieNode* node : cur_nodes){
                if (x == '.'){
                    for (TrieNode* child : node -> vec) if (child != nullptr) next_nodes.push_back(child);
                }
                else{
                    if (node -> vec[x - 'a'] != nullptr) next_nodes.push_back(node -> vec[x - 'a']);
                }
            }
            cur_nodes = next_nodes;
        }
        
        for (TrieNode* node : cur_nodes) if (node -> is_end) return true;
        return false;
    }
};


int main(){
    WordDictionary x;
    x.insert("abcd");
    cout << x.search("a.c.") << '\n';
    cout << x.search("ab..") << '\n';
    cout << x.search("ab.") << '\n';
}
