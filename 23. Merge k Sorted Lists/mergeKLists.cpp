#include <vector>
#include <queue>
using namespace std;




struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


struct Pair{
    int val;
    int No;
    Pair(int value , int Nos) : val(value) , No(Nos){};
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    
}