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



ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.size() == 0) return nullptr;
    auto cmp = [](ListNode* x , ListNode* y){return x -> val > y -> val;};
    priority_queue<ListNode* , vector<ListNode*> , decltype(cmp)> k_minimal_queue(cmp);
    for (ListNode* min_element: lists) {if(min_element != nullptr) k_minimal_queue.push(min_element);}
    if (k_minimal_queue.empty()) return nullptr;
    ListNode *cur = k_minimal_queue.top() , *to_return = k_minimal_queue.top();
    k_minimal_queue.pop();
    if(cur -> next != nullptr) k_minimal_queue.push(cur -> next);
    while (!k_minimal_queue.empty()){
        cur -> next = k_minimal_queue.top();
        k_minimal_queue.pop();
        if(cur -> next -> next != nullptr) k_minimal_queue.push(cur -> next -> next);
        cur = cur -> next;
    }
    return to_return;
}
