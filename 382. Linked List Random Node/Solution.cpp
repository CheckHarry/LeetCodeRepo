#include <vector>
#include <random>
using namespace std;


struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };



class Solution {
private:
    vector<ListNode*> Node_vec;
public:
    Solution(ListNode* head) {
        ListNode* Cur = head;
        while (Cur != nullptr){
            Node_vec.push_back(Cur);
            Cur = Cur ->next;
        }
    }
    
    int getRandom() {
        return Node_vec[rand()%Node_vec.size()] -> val;
    }
};