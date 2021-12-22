void reorderList(ListNode* head) {
        ListNode* NodeVec[50001];
        ListNode* cur = head;
        int index = 0 , left = 0 , right = 0;
        while (cur != NULL) {
            NodeVec[index] = cur;
            cur = cur -> next;
            index ++;
        }
        right = index - 1;
        ListNode* Last = NULL;
        while (right > left){
            NodeVec[left] -> next = NodeVec[right];
            NodeVec[right] ->next = new ListNode(NodeVec[left + 1] -> val);
            NodeVec[left + 1] = NodeVec[right] ->next;
            Last = NodeVec[left];
            left ++;
            right --;
        }
        if (index % 2 == 0) Last->next->next = NULL;
    }