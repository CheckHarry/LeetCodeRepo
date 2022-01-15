#include <vector>
#include <queue>
#include <unordered_map>
#include <iostream>
using namespace std;







int minJumps(vector<int>& arr) {
    if (arr.size() == 1) return 0;
    unordered_map<int , vector<int>> mapping;
    for (int i = 0 ; i < arr.size() ; i ++) mapping[arr[i]].push_back(i);
    vector<bool> marked_node(50001 , false);
    queue<int> Q;
    int length = 0 , queue_size = 1;
    Q.push(0);
    marked_node[0] = true;
    while(!Q.empty()){
        int temp_size = 0;
        for (int j = 0 ; j <  queue_size ; j ++ ){
            int i = Q.front();
            Q.pop();
            if (i + 1 == arr.size() - 1) return length + 1;
            if (i > 0 && marked_node[i - 1] == false){
                Q.push(i - 1);
                marked_node[i - 1] = true;
                temp_size ++;
            }
            if (marked_node[i + 1] == false) {
                Q.push(i + 1);
                marked_node[i + 1] = true;
                temp_size ++;
            }
            for (int x: mapping[arr[i]] ){
                if (x == arr.size() - 1) return length + 1;
                if (marked_node[x] == false){ 
                    Q.push(x);
                    marked_node[x] = true;
                    temp_size ++;
                }
            }
            mapping[arr[i]].clear();
        }
        length ++;
        queue_size = temp_size;
    }
    return length;
}

