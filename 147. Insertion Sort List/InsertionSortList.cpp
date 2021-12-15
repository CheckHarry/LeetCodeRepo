





// Class ListNode is provided by LeetCode
ListNode* insertionSortList(ListNode* head) {
        return insertionSortList_rec(head , head);
    }
    ListNode* insertionSortList_rec(ListNode* head , ListNode* tail){
        if (tail == NULL or tail -> next == NULL) return head; 
        else{
            if (tail -> next -> val < tail -> val){
                ListNode * to_insert = tail -> next;
                tail -> next = tail -> next -> next;
                ListNode  NIL = ListNode(0 , head);
                for (ListNode * Cur = &NIL ; Cur != tail ; Cur = Cur -> next){
                    if ((Cur -> next -> val) > (to_insert -> val)){
                        to_insert -> next = Cur -> next;
                        Cur -> next = to_insert;
                        break;
                    }
                }
                return insertionSortList_rec(NIL.next , tail );
            }
            else return insertionSortList_rec(head , tail->next);
        }
    }