#include <stack>
#include <list>
#include <unordered_map>
#include <iostream>
using namespace std;




class MinStack {
public:
    stack<int> main_stack;
    list<int*> min_list;
    unordered_map<int * , list<int*>::iterator>  min_list_nodes;
    MinStack() {
     
    }

    void push(int val) {
        
        if (main_stack.empty()) {
            main_stack.push(val);
            min_list.push_back(&main_stack.top());
            list<int*>::iterator it = min_list.end();
            --it;
            min_list_nodes.insert(pair<int*, list<int*>::iterator>(&main_stack.top(), it));
        }
        else {
            main_stack.push(val);
            if (**min_list.rbegin() > val) {
                min_list.push_back(&main_stack.top()); 
                list<int*>::iterator it = min_list.end();
                --it;
                min_list_nodes.insert(pair<int*, list<int*>::iterator>(&main_stack.top(), it));
            }
        }
    }

    void pop() {
        int* top = &main_stack.top();
        if (min_list_nodes.find(top) != min_list_nodes.end()) {
            list<int*>::iterator to_erase = min_list_nodes.find(top)->second;
            min_list.erase(to_erase);
            min_list_nodes.erase(top);
        }
        main_stack.pop();
    }

    int top() {
        return main_stack.top();
    }

    int getMin() {
        return **--min_list.end();
    }
};



int main() {
    MinStack x;
    x.push(-3);
    x.push(0);
    x.push(-1);
    x.push(-4);
    cout << x.top() << endl ;
    cout << x.getMin() << endl;
    x.pop();
    cout << x.getMin() << endl;
}