#include <queue>
#include <vector>
using namespace std;




class MedianFinder {
private:
    int size;
    auto cmp = [](int x , int y){return x > y;};
    priority_queue<int> left();
    priority_queue<int , vector<int> , decltype(cmp)> right(cmp);
public:
    MedianFinder() : size(0){
        
    }
    
    void addNum(int num) {
        
    }
    
    double findMedian() {
        if (size % 2 == 0) return double(left.top() + right.top()) / 2;
        else{
            return right.top();
        }
    }
};
