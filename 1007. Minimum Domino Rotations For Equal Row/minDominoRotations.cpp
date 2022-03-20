#include <vector>
using namespace std;




int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
    vector<int> count(7 , 0) ;
    int ans = 20001;
    for (int i = 0 ; i < tops.size() ; i ++){
        count[tops[i]] ++;
        if (tops[i] != bottoms[i]) count[bottoms[i]] ++;
    } 
    for (int i = 1 ; i < 7 ; i ++){
        if (count[i] == tops.size()) {
            int t = 0 , b = 0;
            for (int j = 0 ; j < tops.size() ; j ++){
                if (tops[j] != bottoms[j]){
                    if (tops[j] == i) t ++;
                    else b ++;
                }
            }
            ans = min(t , min(b , ans));
        }
    }
    if (ans == 20001) return -1;
    else return ans;
}


int main(){

}