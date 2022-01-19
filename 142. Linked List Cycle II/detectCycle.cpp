

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
 };


ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head ,  *slow = head;
    while(true){
        if (fast == nullptr || fast -> next == nullptr) return nullptr;
        slow = slow -> next;
        fast = fast -> next -> next;
        if (slow == fast){
            ListNode *goal = head;
            while (goal != slow){
                goal = goal -> next;
                slow = slow -> next;
            }
            return slow;
        }
    }
    return nullptr;
}