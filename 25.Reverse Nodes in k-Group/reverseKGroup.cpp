

// ListNode is a API provided by LeetCode
ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode *cur_node = head , *cur_head = head , *temp = NULL, *to_return = NULL;
        int count = 0;
        while(cur_node != NULL){
            count ++;
            if (count == k) break;
            cur_node = cur_node -> next;
        }
        if (count == k) {
            if (cur_node->next != NULL) temp = reverseKGroup(cur_node-> next , k);
            cur_node -> next = temp;
            return reverseKGroup_head(head , k);
        }
        else return head;
       
    }
    
    ListNode* reverseKGroup_head(ListNode* head , int k){
        if (k == 1) return head;
        else{
            ListNode* next_head = (*head).next;
            ListNode* to_return = reverseKGroup_head(next_head , k - 1);
            (*head).next   = (*next_head).next;
            next_head->next = head;
            return to_return;
        }
    }