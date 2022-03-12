





struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return nullptr;
    int num = head -> val; 
    bool del = false;
    ListNode *cur = head;
    while (cur -> next && cur -> next -> val == num){
        cur = cur -> next;
        del = true;
    }
    if (del) return deleteDuplicates(cur -> next);
    else head -> next = deleteDuplicates(cur -> next);
    return head;
}