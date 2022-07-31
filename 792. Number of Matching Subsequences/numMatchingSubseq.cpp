#include <string>
#include <unordered_map>
#include <vector>
using namespace std;


class Solution {
public:
    
    struct TrieNode {
        char value;
        int word_count;
        int pos;
        vector<TrieNode*> child;
        TrieNode(int _value) : value(_value) , word_count(0) , child(26 , nullptr) , pos(-1) {};
    };
    
    TrieNode *root;
    int ans = 0;
    void dfs(TrieNode *root , string &s , int prev_pos , unordered_map<char , vector<int>> &mapping)
    {   
        int pos = -1;
       
        if (mapping[root -> value].size() == 0 && root -> value != 0)    
            return;
        else
        {
            for (int _pos : mapping[root -> value])
            {
                
                if (_pos > prev_pos)
                {
                    pos = _pos;
                    break;
                }
            }
                
        }
        
        
            if (pos == -1 && root -> value != 0)
                return;
            else
            {
                ans += root -> word_count;
                    
                for (TrieNode *chi : root -> child)        
                {
                    if (chi)
                        dfs(chi , s , pos , mapping);
                }
            }
        }
        
        
        
    
    
    int numMatchingSubseq(string s, vector<string>& words) {
        root = new TrieNode(0);
        unordered_map<char , vector<int>> mapping;
        
        for (int i = 0 ; i < s.size() ; i ++)
            mapping[s[i]].push_back(i);
        
        
        for (string &s : words)
        {
            TrieNode *cur = root;
            for (int i = 0 ; i < s.size() ; i ++)
            {
                char c = s[i];
                if (cur -> child[c - 'a'] == nullptr)
                    cur -> child[c - 'a'] = new TrieNode(c);
                cur = cur -> child[c - 'a'];
                if (i == s.size() - 1)
                    cur -> word_count ++;
            }
        }
        dfs(root , s , -1 , mapping);
        return ans;
    }
};
