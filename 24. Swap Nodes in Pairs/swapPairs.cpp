




struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



ListNode* swapPairs(ListNode* head) {
    if (head == nullptr || head->next == nullptr  ) return head;
    ListNode *slow = head , *fast = head -> next , *ans = head -> next , *prev = nullptr;
    int count = 0;
    while(fast != nullptr){
        if (count % 2 == 0){
            slow->next = fast->next;
            fast->next = slow;
            if(prev != nullptr) prev -> next = fast;
            slow = fast;
            fast = fast -> next;
            prev = fast;
        }
        slow = slow -> next;
        fast = fast -> next;
        count ++;
    }
    return ans;
}