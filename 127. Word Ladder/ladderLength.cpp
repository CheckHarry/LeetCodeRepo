#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <iostream>
using namespace std;


int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int count = 0;
    queue<string> node_queue;
    unordered_set<string> seen;
    unordered_set<string> word_set;
    string temp;
    node_queue.push(beginWord);
    seen.insert(beginWord);
    for (string &s : wordList) word_set.insert(s);
    while (!node_queue.empty()){
        count ++;
        queue<string> new_queue;
        while(!node_queue.empty()){
            for (int i = 0 ; i < beginWord.size() ; i ++){
                temp = node_queue.front();
                for (int j = 0 ; j < 26 ; j ++){
                    temp[i] = 'a' + j;
                    if (word_set.find(temp) != word_set.end() && seen.find(temp) == word_set.end()) {
                        if (temp == endWord) return count + 1;
                        new_queue.push(temp);
                        seen.insert(temp);
                    }
                }
            }
            node_queue.pop();
        }
        node_queue = move(new_queue);
    }
    return 0;
}

int main(){
    vector<string> x{"abc" , "cab" , "cog" , "dog" , "doc" , "bog" , "cao" , "cob" , "aac" , "aab"};
    cout << ladderLength("abc" , "cob" , x);
}

