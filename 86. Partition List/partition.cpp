

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *partition(ListNode *head, int x)
{
    ListNode dummy_less, dummy_large;
    ListNode *cur_less = &dummy_less, *cur_large = &dummy_large;
    ListNode *temp_less = cur_less, *temp_large = cur_large;
    ListNode *cur = head;
    while (cur)
    {
        if (cur->val < x)
        {
            cur_less->next = cur;
            cur_less = cur_less->next;
        }
        else
        {
            cur_large->next = cur;
            cur_large = cur_large->next;
        }
        cur = cur->next;
    }
    cur_large->next = nullptr;
    cur_less->next = temp_large->next;

    return temp_less->next;
}