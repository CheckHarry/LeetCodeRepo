#include <vector>
#include <queue>
#include <iostream>
using namespace std;



static int l2norm(const vector<int> &v){
    return v[0]*v[0] + v[1]*v[1];
}
struct compar{
private:
    vector<vector<int>> * points;
public:
    compar(vector<vector<int>> * points_ptr) : points(points_ptr){};
    bool operator()(int a  , int b){
        return l2norm((*points)[a]) < l2norm((*points)[b]);
    };
};


vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
    compar x(&points);
    priority_queue<int , vector<int> , compar> Q(x);
    vector<vector<int>> to_return;
    for (int i = 0 ; i < k ; i++) Q.push(i);
    for (int i = k ; i < points.size() ; i++){
        if(l2norm(points[i]) < l2norm(points[Q.top()])){
            Q.pop();
            Q.push(i);
        }
    }
	
    while(!Q.empty()){
        to_return.emplace_back(points[Q.top()]);
        Q.pop();
    }
    return to_return;
    
}




int main(){
    vector<vector<int>> x({{-5,4},{-6,-5},{4,6}});
    auto a = kClosest(x , 2);
    for (auto v : a){
        for (auto coor: v) cout << coor <<',';
        cout << '\n';
    }
}