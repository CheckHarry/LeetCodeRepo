#include <queue>
#include <vector>
#include <iostream>
using namespace std;



auto cmp = [](int x , int y){return x > y;};
class MedianFinder {
private:
    int size;
    priority_queue<int> left;
    priority_queue<int , vector<int> , decltype(cmp)> right{cmp};
public:
    MedianFinder() : size(0){
        left.push(-100001);
        right.push(100001);
    }
    
    void addNum(int num) {
       if (size % 2 == 0) {
           if (num <= left.top()){
               right.push(left.top());
               left.pop();
               left.push(num);
           }
           else right.push(num);
       }
       else{
           if (num >= right.top()){
                left.push(right.top());
                right.pop();
                right.push(num);
           }
           else left.push(num);
       }
       size ++;
    }
    
    double findMedian() {
        if (size % 2 == 0) return double(left.top() + right.top()) / 2;
        else{
            return right.top();
        }
    }
};

int main(){
    MedianFinder MF;
    MF.addNum(1);

    cout << MF.findMedian();
}