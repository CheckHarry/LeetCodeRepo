#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;





vector<int> findSubstring(string s, vector<string>& words) {
    unordered_map<string , int> word_table ;
    vector<int> to_return{};
    int word_size = words[0].size();
    for (auto&& x : words) if (word_table.find(x) == word_table.end()) word_table.insert(pair<string , int>(x,1)) ; else word_table[x] ++ ;
    if (s.size() < word_size * words.size()) return to_return;
    for (int i = 0 ; i < word_size ; i ++){
        unordered_map<string , int> word_count;
        queue<string> word_queue;
        int count_match = 0 , index = i , cur_size = 0;
        for (auto&& x : words) if (word_count.find(x) == word_count.end()) word_count.insert(pair<string , int>(x,0));
        char cur[31] ;
        memset(cur , 0 , sizeof(cur));
        for (string::iterator it = s.begin() + i ; it < s.end() ; it ++){
            cur[cur_size] = *it;
            cur_size ++;
            if (cur_size == word_size) {
                word_queue.push(string(cur));
                if(word_count.find(cur) != word_count.end()) {
                    if(word_count[cur] == word_table[cur]) count_match -- ;
                    word_count[cur] ++ ;
                    if(word_count[cur] == word_table[cur]) count_match ++ ;
                }
                cur_size = 0;
            }
            if (word_queue.size() > words.size()){
                string front = word_queue.front();
                if(word_count.find(front) != word_count.end()) {
                    if(word_count[front] == word_table[front]) count_match -- ;
                    word_count[front] -- ;
                    if(word_count[front] == word_table[front]) count_match ++ ;
                }
                word_queue.pop();
            }
            if (cur_size == 0 && count_match == word_count.size()) to_return.push_back(index + 1 - words.size()*word_size);
            index ++;
        }
    }
    return to_return;
}


int main(){
    vector<string> words({"foo","bar"});
    vector<int> ans = findSubstring("barfoothefoobarman" , words);
    cout << '\n';
    for (int i : ans ) cout << i << ',';
}