

ListNode* middleNode(ListNode* head) {
        ListNode* middle = head , *cur = head;
        bool to_jump = true;
        while(cur ->next != NULL){
            if (to_jump) middle = middle -> next;
            to_jump = !to_jump;
            cur = cur -> next;
        }
        return middle;
    }