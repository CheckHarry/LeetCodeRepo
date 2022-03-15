





struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int add = 0;
    ListNode *cur1 = l1 , *cur2 = l2 , *ans = l1 , *prev = nullptr;
    while (cur1 || cur2){
        if (cur1 && cur2){
            cur1 -> val = cur1 -> val + cur2 -> val + add;
            add = cur1 -> val / 10;
            cur1 -> val = cur1 -> val % 10;
        }
        else if(cur1){
            cur1 -> val = cur1 -> val + add;
            add = (cur1 -> val) / 10;
            cur1 -> val = cur1 -> val % 10;
        }
        if (!cur1 -> next && cur2){
            cur1 -> next = cur2 -> next;
            cur2 -> next = nullptr;
        }
        prev = cur1;
        if (cur1) cur1 = cur1 -> next;
        if (cur2) cur2 = cur2 -> next;
    }
    if(add) prev -> next = new ListNode(1);
    return ans;
}