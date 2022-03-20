#include <list>
#include <unordered_map>
#include <queue>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;





class FreqStack {
public:
    unordered_map<int , int> freq_mapping;
    unordered_map<int , stack<int>> freq_stack_mapping;
    int max_freq = 0;
    FreqStack() {
        
    }
    
    void push(int val) {
        freq_mapping[val] ++;
        freq_stack_mapping[freq_mapping[val]].push(val);
        if (freq_mapping[val] > max_freq) max_freq = freq_mapping[val];
    }
    
    int pop() {
        int to_return = freq_stack_mapping[max_freq].top();
        freq_stack_mapping[max_freq].pop();
        freq_mapping[to_return] --;
        if (freq_stack_mapping[max_freq].empty()) max_freq --;
        return to_return;
    }
};



unordered_map<int , int> mapping{{1 , 100} , {2 , 50} , {3 , 70}};




int main(){
    FreqStack s;
    s.push(1);
    s.push(1);
    s.push(2);
    cout << s.pop();
    cout << s.pop();
    cout << s.pop();
}